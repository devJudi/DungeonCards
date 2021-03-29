#include "CardHero.h"

CardHero::CardHero(Heroes hero)
    :Card()
{
    heroType = hero;
    heroWeapon = none;
    lastWeaponUsed = none;
    this->setCardGraphics();
    currentCooldown = 0;
    skillImprovements = 0;
}

CardHero::CardHero(const CardHero &copiedCard)
    :Card()
{
    heroType = copiedCard.heroType;
    this->setCardGraphics();
    heroWeapon = copiedCard.heroWeapon;
    cardShape.setPosition(copiedCard.cardShape.getPosition());
    hp = copiedCard.hp;
    attack = copiedCard.attack;
    showInfo = copiedCard.showInfo;
    currentCooldown = copiedCard.currentCooldown;
    skillImprovements = copiedCard.skillImprovements;
    skillCooldown = copiedCard.skillCooldown;
}

CardHero::~CardHero()
{
    //dtor
}

void CardHero::doAction()
{
    std::cout<<"im a hero"<<std::endl;
}

bool CardHero::mouseClicked(sf::Vector2i mousePos, Card* cards[9], CardHero* hero)
{
    if(mousePos.x>=cardShape.getPosition().x&&
            mousePos.x<=cardShape.getPosition().x+WIDTH*0.12&&
            mousePos.y>=cardShape.getPosition().y&&
            mousePos.y<=cardShape.getPosition().y+HEIGHT*0.3)
    {
        std::cout<<"My coords: "<<cardShape.getPosition().x<<", "<<cardShape.getPosition().y<<std::endl;
        return true;
    }
    else return false;
}

void CardHero::drawHp(sf::RenderWindow &window)
{
    sf::Text textHp;

    int offset = 0;
    if(hp<-99||hp>99) offset = 2;
    else if(hp<-9||hp>9) offset = 1;
    else offset = 0;
    if(hp<0) offset++;

    textHp.setString(std::to_string(hp));
    textHp.setFillColor(sf::Color::Red);
    textHp.setFont(fontPixel);
    textHp.setPosition(cardShape.getPosition().x+WIDTH*0.1-offset*WIDTH*0.01, cardShape.getPosition().y+HEIGHT*0.01);
    textHp.setCharacterSize(WIDTH*0.02);

    window.draw(textHp);

    sf::Text textAttack;
    textAttack.setString(std::to_string(attack));
    textAttack.setFillColor(sf::Color::Red);
    textAttack.setFont(fontPixel);
    textAttack.setPosition(cardShape.getPosition().x+WIDTH*0.005, cardShape.getPosition().y+HEIGHT*0.25);
    textAttack.setCharacterSize(WIDTH*0.02);

    window.draw(textAttack);
}

CardTypes CardHero::getCardType()
{
    return cardHero;
}

void CardHero::setCardGraphics()
{
    switch(heroType)
    {
    case knight:
        cardShape.setTexture(&texCardHeroKnight);
        infoShape.setTexture(&texInfoKnight);
        maxHp = 10;
        hp = maxHp;
        giveWeapon(sword, 10);
        skillCooldown = 7;
        break;

    case mage:
        cardShape.setTexture(&texCardHeroMage);
        infoShape.setTexture(&texInfoMage);
        maxHp = 8;
        hp = maxHp;
        giveWeapon(wandIce, 10);
        skillCooldown = 10;
        break;

    case rouge:
        cardShape.setTexture(&texCardHeroRouge);
        infoShape.setTexture(&texInfoRouge);
        maxHp = 7;
        hp = maxHp;
        giveWeapon(poisonedDagger, 3);
        skillCooldown = 10;
        break;

    }
}

int CardHero::doAttack(int opponentHp)
{
    if(attack>0)
    {
        isWeaponUsed = true;
        lastWeaponUsed = heroWeapon;

        if(heroWeapon == wandIce) soundWeaponWand.play();
        else soundWeaponMelee.play();

        if(heroWeapon == poisonedDagger)
        {
            attack--;
            if(attack==0) heroWeapon = none;
            return 0;
        }
        else
        {
            if(attack>opponentHp)
            {
                attack-=opponentHp;
                return 0;
            }
            else if(attack==opponentHp)
            {
                attack = 0;
                heroWeapon = none;
                return 0;
            }
            else
            {
                int dmg = attack;
                attack = 0;
                heroWeapon = none;
                return opponentHp-dmg;
            }
        }
    }
    else
    {
        isWeaponUsed = false;
        lastWeaponUsed = none;

        if(hp>opponentHp)
        {
            hp-=opponentHp;
            return 0;
        }
        else if(hp==opponentHp)
        {
            hp = 0;
            isGameOver = true;
            soundGameOver.play();
            return 0;
        }
        else
        {
            int dmg = hp;
            hp -= opponentHp;
            isGameOver = true;
            soundGameOver.play();
            return opponentHp-dmg;
        }
    }
}

void CardHero::giveWeapon(Weapons weapon, int damage)
{
    if(heroWeapon != none)
    {
        if(damage>attack)
        {
            if(heroWeapon == poisonedDagger)
            {
                if(weapon == poisonedDagger)
                {
                    attack = damage;
                    heroWeapon = weapon;
                }
            }
            else
            {
                attack = damage;
                heroWeapon = weapon;
            }
        }
    }
    else
    {
        attack = damage;
        heroWeapon = weapon;
    }
}

bool CardHero::increasceHp()
{
    if(earnedCoins>=100)
    {
        if(maxHp<15)
        {
            earnedCoins-=100;
            maxHp++;
            hp++;
            return true;
        }
        else return false;
    }
    else return false;
}

bool CardHero::decreasceSkillCooldown()
{
    if(earnedCoins>=125)
    {
        if(skillCooldown>5)
        {
            earnedCoins-=125;
            skillCooldown--;
            return true;
        }
        else return false;
    }
    else return false;
}

bool CardHero::improveSkill()
{
    if(earnedCoins>=150)
    {
        if(skillImprovements<3)
        {
            earnedCoins-=150;
            skillImprovements++;
        }
        else return false;
    }
    else return false;
}


//////////////////////////// Card class function //////////////////////////////////////////

bool Card::mouseClicked(sf::Vector2i mousePos, Card* cards[9], CardHero* hero)
{
    if(mousePos.x>=cardShape.getPosition().x&&
            mousePos.x<=cardShape.getPosition().x+WIDTH*0.12&&
            mousePos.y>=cardShape.getPosition().y&&
            mousePos.y<=cardShape.getPosition().y+HEIGHT*0.3)
    {
        int heroX = (hero->cardShape.getPosition().x-WIDTH*0.31)/(WIDTH*0.12);
        int heroY = (hero->cardShape.getPosition().y-HEIGHT*0.025)/(HEIGHT*0.3);
        int x = (cardShape.getPosition().x-WIDTH*0.31)/(WIDTH*0.12);
        int y = (cardShape.getPosition().y-HEIGHT*0.025)/(HEIGHT*0.3);

        if(x == heroX)
        {
            if((y-heroY)!=2 && (heroY-y)!=2)
            {
                deleteMe = true;
                totalSteps++;
                return true;
            }
        }
        else if(y == heroY)
        {
            if((x-heroX)!=2 && (heroX-x)!=2)
            {
                deleteMe = true;
                totalSteps++;
                return true;
            }
        }
        else std::cout<<"Invalid target!"<<std::endl;

    }
    return false;
}

