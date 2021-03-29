#include "CardMonster.h"

CardMonster::CardMonster()
    :Card()
{
    int random = rand()%5;
    monsterType = Monsters(random);
    this->setCardGraphics();
    lastDamage = 0;
}

CardMonster::CardMonster(const CardMonster &copiedCard)
    :Card()
{
    monsterType = copiedCard.monsterType;
    this->setCardGraphics();
    hp = copiedCard.hp;
    cardShape.setPosition(copiedCard.cardShape.getPosition());
    showInfo = copiedCard.showInfo;
}

CardMonster::~CardMonster()
{
    //dtor
}

void CardMonster::doAction(Card* cards[9], CardHero* hero)
{
    int heroX = (hero->cardShape.getPosition().x-WIDTH*0.31)/(WIDTH*0.12);
    int heroY = (hero->cardShape.getPosition().y-HEIGHT*0.025)/(HEIGHT*0.3);
    int x = (cardShape.getPosition().x-WIDTH*0.31)/(WIDTH*0.12);
    int y = (cardShape.getPosition().y-HEIGHT*0.025)/(HEIGHT*0.3);

    bool dealExtendedDamage = false;

    if(x == heroX)
    {
        switch(heroY)
        {
        case 0:
            if(cards[6+heroX]->getCardType() == cardMonster)
            {
                if(dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon == wandIce)
                    dealExtendedDamage = true;
            }
            break;

        case 1:
            break;

        case 2:
            if(cards[heroX]->getCardType() == cardMonster)
            {
                if(dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon == wandIce)
                    dealExtendedDamage = true;
            }
            break;

        }

        if((y-heroY)!=2 && (heroY-y)!=2)
        {

            if(dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon == sword || dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon == poisonedDagger)
                animationSword[x+y*3] = 8;

            else if(dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon == wandIce)
                animationWandIce[x+y*3] = 8;

            int damage = hp - hero->doAttack(hp);

            if(dealExtendedDamage)
            {
                if(heroY == 0)
                {
                    dynamic_cast<CardMonster*>(cards[6+heroX])->hp -= damage;
                    if(dynamic_cast<CardMonster*>(cards[6+heroX])->hp <= 0)
                        cards[6+heroX]->deleteMe = true;

                    if(dynamic_cast<CardHero*>(cards[heroIndex])->lastWeaponUsed == wandIce)
                        animationWandIce[6+heroX] = 8;
                }
                else if(heroY == 2)
                {
                    dynamic_cast<CardMonster*>(cards[heroX])->hp -= damage;
                    if(dynamic_cast<CardMonster*>(cards[heroX])->hp <= 0)
                        cards[heroX]->deleteMe = true;

                    if(dynamic_cast<CardHero*>(cards[heroIndex])->lastWeaponUsed == wandIce)
                        animationWandIce[heroX] = 8;
                }
            }

            hp -= damage;
            if(hp<=0) deleteMe = true;
            totalSteps++;
        }
    }
    else if(y == heroY)
    {
        switch(heroX)
        {
        case 0:
            if(cards[2+heroY*3]->getCardType() == cardMonster)
            {
                if(dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon == wandIce)
                    dealExtendedDamage = true;
            }
            break;

        case 1:
            break;

        case 2:
            if(cards[heroY*3]->getCardType() == cardMonster)
            {
                if(dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon == wandIce)
                    dealExtendedDamage = true;
            }
            break;

        }

        if((x-heroX)!=2 && (heroX-x)!=2)
        {
            if(dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon == sword || dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon == poisonedDagger)
                animationSword[x+y*3] = 8;

            else if(dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon == wandIce)
                animationWandIce[x+y*3] = 8;

            int damage = hp - hero->doAttack(hp);

            if(dealExtendedDamage)
            {
                if(heroX == 0)
                {
                    dynamic_cast<CardMonster*>(cards[2+heroY*3])->hp -= damage;
                    if(dynamic_cast<CardMonster*>(cards[2+heroY*3])->hp <= 0)
                        cards[2+heroY*3]->deleteMe = true;

                    if(dynamic_cast<CardHero*>(cards[heroIndex])->lastWeaponUsed == wandIce)
                        animationWandIce[2+heroY*3] = 8;
                }
                else if(heroX == 2)
                {
                    dynamic_cast<CardMonster*>(cards[heroY*3])->hp -= damage;
                    if(dynamic_cast<CardMonster*>(cards[heroY*3])->hp <= 0)
                        cards[heroY*3]->deleteMe = true;

                    if(dynamic_cast<CardHero*>(cards[heroIndex])->lastWeaponUsed == wandIce)
                        animationWandIce[heroY*3] = 8;
                }
            }

            hp -= damage;
            if(hp<=0) deleteMe = true;
            totalSteps++;
        }
    }
    else std::cout<<"Invalid target!"<<std::endl;

    if(deleteMe == true)
    {
        switch(monsterType)
        {
        case zombie:
            soundZombie.play();
            break;

        case skeleton:
            soundSkeleton.play();
            break;

        case spider:
            soundSpider.play();
            break;

        case bat:
            soundBat.play();
            break;

        case ghost:
            soundGhost.play();
            break;
        }
    }
}

bool CardMonster::mouseClicked(sf::Vector2i mousePos, Card* cards[9], CardHero* hero)
{
    if(mousePos.x>=cardShape.getPosition().x&&
            mousePos.x<=cardShape.getPosition().x+WIDTH*0.12&&
            mousePos.y>=cardShape.getPosition().y&&
            mousePos.y<=cardShape.getPosition().y+HEIGHT*0.3)
    {
        doAction(cards, hero);
        return true;
    }
    else return false;
}

void CardMonster::drawHp(sf::RenderWindow &window)
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
}

CardTypes CardMonster::getCardType()
{
    return cardMonster;
}

void CardMonster::setCardGraphics()
{
    switch(monsterType)
    {
    case zombie:
        cardShape.setTexture(&texCardMonsterZombie);
        infoShape.setTexture(&texInfoZombie);
        hp = rand()%(3+totalSteps/40)+3+(totalSteps/60);
        fullHp = hp;
        break;

    case skeleton:
        cardShape.setTexture(&texCardMonsterSkeleton);
        infoShape.setTexture(&texInfoSkeleton);
        hp = rand()%(4+totalSteps/40)+2+(totalSteps/60);
        fullHp = hp;
        break;

    case ghost:
        cardShape.setTexture(&texCardMonsterGhost);
        infoShape.setTexture(&texInfoGhost);
        hp = rand()%(5+totalSteps/40)+2+(totalSteps/60);
        fullHp = hp;
        break;

    case spider:
        cardShape.setTexture(&texCardMonsterSpider);
        infoShape.setTexture(&texInfoSpider);
        hp = rand()%(3+totalSteps/40)+2+(totalSteps/60);
        fullHp = hp;
        break;

    case bat:
        cardShape.setTexture(&texCardMonsterBat);
        infoShape.setTexture(&texInfoBat);
        hp = rand()%(2+totalSteps/40)+2+(totalSteps/60);
        fullHp = hp;
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////////

void CardHero::useSkill(Card* cards[9])
{
    switch(heroType)
    {
    case knight:
        soundSkillKnight.play();
        for(int i = 0; i<9; i++)
        {
            if(cards[i]->getCardType() == cardMonster)
            {
                if(dynamic_cast<CardMonster*>(cards[i])->hp!=1)
                    animationSword[i] = 24;

                if(dynamic_cast<CardMonster*>(cards[i])->hp>3)
                {
                    dynamic_cast<CardMonster*>(cards[i])->hp/=2;
                    if(dynamic_cast<CardMonster*>(cards[i])->hp+1<skillImprovements)
                    {
                        dynamic_cast<CardMonster*>(cards[i])->hp = 1;
                    }
                    else dynamic_cast<CardMonster*>(cards[i])->hp -=skillImprovements;
                }
                else dynamic_cast<CardMonster*>(cards[i])->hp=1;
            }
        }
        if(maxHp-hp>(3+skillImprovements/2)) hp+=(3+skillImprovements/2);
        else hp = maxHp;
        break;

    case mage:
        soundSkillMage.play();
        for(int i = 0; i<9; i++)
        {
            if(cards[i]->getCardType() == cardMonster)
            {
                if(dynamic_cast<CardMonster*>(cards[i])->hp!=1)
                    animationWandIce[i] = 24;

                if(dynamic_cast<CardMonster*>(cards[i])->hp>3+skillImprovements)
                    dynamic_cast<CardMonster*>(cards[i])->hp-=2+skillImprovements;

                else
                    dynamic_cast<CardMonster*>(cards[i])->hp=1;
            }
            else if(cards[i]->getCardType() == cardWeapon)
            {
                animationWandIce[i] = 24;
                dynamic_cast<CardWeapon*>(cards[i])->damage+=3+skillImprovements;
            }
            else if(cards[i]->getCardType() == cardTreasure)
            {
                if(dynamic_cast<CardTreasure*>(cards[i])->treasureType == coin || dynamic_cast<CardTreasure*>(cards[i])->treasureType == healthPotion)
                {
                    animationWandIce[i] = 24;
                    dynamic_cast<CardTreasure*>(cards[i])->ammount+=3+skillImprovements;
                }
                else if(dynamic_cast<CardTreasure*>(cards[i])->treasureType == chest)
                {
                    animationWandIce[i] = 24;
                    cards[i]->deleteMe = true;
                    std::cout<<"deleting chest..."<<std::endl;
                }
            }
        }
        break;

    case rouge:
        int monsterNumber = 0;
        for(int i = 0; i<9; i++)
        {
            if(cards[i]->getCardType() == cardMonster)
            {
                monsterNumber++;
            }
        }

        if(monsterNumber>0)
        {
            soundSkillRouge.play();
            int monsterTab[monsterNumber] = {0};
            int index = 0;
            for(int i = 0; i<9; i++)
            {
                if(cards[i]->getCardType() == cardMonster)
                {
                    monsterTab[index] = i;
                    index++;
                }
            }

            if(monsterNumber == 1)
            {
                int random = rand()%monsterNumber;
                animationChange[monsterTab[random]] = 8;
                delete cards[monsterTab[random]];
                cards[monsterTab[random]] = new CardTreasure(healthPotion);
                cards[monsterTab[random]]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(monsterTab[random]%3),
                        HEIGHT*0.025+HEIGHT*0.325*(monsterTab[random]/3));
            }
            else
            {
                int random1 = rand()%monsterNumber;
                int random2 = rand()%monsterNumber;
                while(random1==random2)
                {
                    random2 = rand()%monsterNumber;
                }

                if(rand()%(4-skillImprovements)==0 && skillImprovements!=0)
                {
                    animationChange[monsterTab[random1]] = 8;
                    delete cards[monsterTab[random1]];
                    cards[monsterTab[random1]] = new CardTreasure(healthPotion);
                    cards[monsterTab[random1]]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(monsterTab[random1]%3),
                            HEIGHT*0.025+HEIGHT*0.325*(monsterTab[random1]/3));

                    animationChange[monsterTab[random2]] = 8;
                    delete cards[monsterTab[random2]];
                    cards[monsterTab[random2]] = new CardTreasure(healthPotion);
                    cards[monsterTab[random2]]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(monsterTab[random2]%3),
                            HEIGHT*0.025+HEIGHT*0.325*(monsterTab[random2]/3));
                }
                else
                {
                    animationChange[monsterTab[random1]] = 8;
                    delete cards[monsterTab[random1]];
                    cards[monsterTab[random1]] = new CardTreasure(healthPotion);
                    cards[monsterTab[random1]]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(monsterTab[random1]%3),
                            HEIGHT*0.025+HEIGHT*0.325*(monsterTab[random1]/3));
                }
            }

        }
        break;
    }

    currentCooldown-=skillCooldown;
}
