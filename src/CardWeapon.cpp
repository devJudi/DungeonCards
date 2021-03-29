#include "CardWeapon.h"

CardWeapon::CardWeapon()
    :Card()
{
    int random = rand()%2;
    if(random == 1) weaponType = sword;
    else weaponType = wandIce;

    this->setDamage();
}

CardWeapon::CardWeapon(Weapons weapon)
    :Card()
{
    if(weapon == poisonedDagger)
    {
            int random = rand()%3;
            if(random == 0) weaponType = sword;
            else if(random == 1) weaponType = wandIce;
            else weaponType = poisonedDagger;

            this->setDamage();
    }
    else
    {
        weaponType = weapon;
        this->setDamage();
    }

}

CardWeapon::CardWeapon(const CardWeapon &copiedCard)
    :Card()
{
    weaponType = copiedCard.weaponType;
    this->setDamage();
    damage = copiedCard.damage;
    cardShape.setPosition(copiedCard.cardShape.getPosition());
    showInfo = copiedCard.showInfo;
}

CardWeapon::~CardWeapon()
{
    //dtor
}

void CardWeapon::drawHp(sf::RenderWindow &window)
{
    sf::Text textDamage;

    int offset = 0;
    if(damage<-99||damage>99) offset = 2;
    else if(damage<-9||damage>9) offset = 1;
    else offset = 0;
    if(damage<0) offset++;

    textDamage.setString(std::to_string(damage));
    textDamage.setFillColor(sf::Color::Red);
    textDamage.setFont(fontPixel);
    textDamage.setPosition(cardShape.getPosition().x+WIDTH*0.1-offset*WIDTH*0.01, cardShape.getPosition().y+HEIGHT*0.01);
    textDamage.setCharacterSize(WIDTH*0.02);

    window.draw(textDamage);
}

bool CardWeapon::mouseClicked(sf::Vector2i mousePos, Card* cards[9], CardHero* hero)
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
                hero->giveWeapon(weaponType, damage);
                deleteMe = true;
                totalSteps++;
                return true;
            }
        }
        else if(y == heroY)
        {
            if((x-heroX)!=2 && (heroX-x)!=2)
            {
                hero->giveWeapon(weaponType, damage);
                deleteMe = true;
                totalSteps++;
                return true;
            }
        }
        else std::cout<<"Invalid target!"<<std::endl;
    }

    return false;
}

CardTypes CardWeapon::getCardType()
{
    return cardWeapon;
}

void CardWeapon::setDamage()
{
    switch(weaponType)
    {
    case sword:
        cardShape.setTexture(&texCardWeaponSword);
        infoShape.setTexture(&texInfoSword);
        damage = 3 + rand()%4;
        break;

    case wandIce:
        cardShape.setTexture(&texCardWeaponWandIce);
        infoShape.setTexture(&texInfoWandIce);
        damage = 2 + rand()%6;
        break;

    case poisonedDagger:
        cardShape.setTexture(&texCardWeaponPoisonedDagger);
        infoShape.setTexture(&texInfoPoisonedDagger);
        damage = 1 + rand()%3;

    case none:
        break;
    }
}
