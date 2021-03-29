#include "GameEngine.h"

GameEngine::GameEngine()
{
    //ctor
}

GameEngine::~GameEngine()
{
    //dtor
}

void GameEngine::createNewCard(Card* cards[9], int number)
{
    int random = rand()%10;

    if(random==0)
    {
        cards[number] = new Card();
    }
    else if(random<6)
    {
        cards[number] = new CardMonster();
    }
    else if(random == 7)
    {
        if(currentHeroType == mage)
        {
            cards[number] = new CardWeapon(wandIce);
        }
        else if(currentHeroType == rouge)
        {
            cards[number] = new CardWeapon(poisonedDagger);
        }
        else
        {
            cards[number] = new CardWeapon();
        }
    }
    else
    {
        cards[number] = new CardTreasure();
    }
    cards[number]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(number%3), HEIGHT*0.025+HEIGHT*0.325*(number/3));

    animationTime[number] = 30;
}

void GameEngine::moveCards(Card* cards[9])
{
    for(int i = 0; i<9; i++)
    {
        if(cards[i]->deleteMe == true)
        {
            bool isChest = false;
            bool isMonster = false;

            if(cards[i]->getCardType() == cardTreasure)
            {
                if(dynamic_cast<CardTreasure*>(cards[i])->treasureType == chest)
                {
                    int random = rand()%3;
                    if(random == 0)
                    {
                        dynamic_cast<CardTreasure*>(cards[i])->treasureType = coin;
                        dynamic_cast<CardTreasure*>(cards[i])->setCardGraphics();
                    }
                    else if(random == 1)
                    {
                        dynamic_cast<CardTreasure*>(cards[i])->treasureType = healthPotion;
                        dynamic_cast<CardTreasure*>(cards[i])->setCardGraphics();
                    }
                    else if(random == 2)
                    {
                        delete cards[i];
                        if(dynamic_cast<CardHero*>(cards[heroIndex])->heroType == mage)
                        {
                            cards[i] = new CardWeapon(wandIce);
                        }
                        else if(dynamic_cast<CardHero*>(cards[heroIndex])->heroType == rouge)
                        {
                            cards[i] = new CardWeapon(poisonedDagger);
                        }
                        else cards[i] = new CardWeapon;
                    }

                    cards[i]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(i%3), HEIGHT*0.025+HEIGHT*0.325*(i/3));
                    animationTime[i] = 30;

                    isChest = true;
                    cards[i]->deleteMe = false;
                }
                else if(dynamic_cast<CardTreasure*>(cards[i])->treasureType == coin)
                {
                    dynamic_cast<CardHero*>(cards[heroIndex])->currentCooldown+=1;
                    if(dynamic_cast<CardHero*>(cards[heroIndex])->currentCooldown >= dynamic_cast<CardHero*>(cards[heroIndex])->skillCooldown)
                        dynamic_cast<CardHero*>(cards[heroIndex])->useSkill(cards);
                }
                else if(dynamic_cast<CardTreasure*>(cards[i])->treasureType == rubin)
                {
                    dynamic_cast<CardHero*>(cards[heroIndex])->currentCooldown+=5;
                    if(dynamic_cast<CardHero*>(cards[heroIndex])->currentCooldown >= dynamic_cast<CardHero*>(cards[heroIndex])->skillCooldown)
                        dynamic_cast<CardHero*>(cards[heroIndex])->useSkill(cards);
                }
            }
            else if(cards[i]->getCardType() == cardMonster)
            {
                if(dynamic_cast<CardHero*>(cards[heroIndex])->isWeaponUsed == true)
                {

                    int droppedGold = dynamic_cast<CardMonster*>(cards[i])->fullHp;
                    delete cards[i];

                    cards[i] = new CardTreasure;
                    dynamic_cast<CardTreasure*>(cards[i])->treasureType = coin;
                    dynamic_cast<CardTreasure*>(cards[i])->setCardGraphics();
                    dynamic_cast<CardTreasure*>(cards[i])->ammount = droppedGold;

                    cards[i]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(i%3), HEIGHT*0.025+HEIGHT*0.325*(i/3));
                    animationTime[i] = 30;

                    isMonster = true;
                    cards[i]->deleteMe = false;
                }

            }

            if(!isChest && !isMonster)
            {

                delete cards[i];
                cards[i] = new CardHero(*dynamic_cast<CardHero*>(cards[heroIndex]));

                std::cout<<"Making animation time: ";
                if(heroIndex+1 == i) animationRight[i] = 20;
                else if(heroIndex-1 == i) animationLeft[i] = 20;
                else if(heroIndex+3 == i) animationDown[i] = 20;
                else if(heroIndex-3 == i) animationUp[i] = 20;
                else cards[i]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(i%3), HEIGHT*0.025+HEIGHT*0.325*(i/3));
                std::cout<<"Done!"<<std::endl;

                std::cout<<"Deleting heroIndex card: ";
                delete cards[heroIndex];
                std::cout<<"Done!"<<std::endl;

                std::cout<<"Copying and creating cards: ";
                if(heroIndex+1 == i)
                {
                    if(heroIndex%3 == 1)
                    {
                        copyCard(cards, heroIndex-1);
                        animationRight[heroIndex] = 20;
                        // heroIndex-1
                    }
                    else
                    {
                        if(heroIndex == 3)
                        {
                            copyCard(cards, 6);
                            animationUp[heroIndex] = 20;
                            // 6
                        }
                        else
                        {
                            copyCard(cards, 3);
                            if(heroIndex == 0) animationUp[heroIndex] = 20;
                            else animationDown[heroIndex] = 20;
                            // 3
                        }
                    }
                }
                else if(heroIndex-1 == i)
                {
                    if(heroIndex%3 == 1)
                    {
                        copyCard(cards, heroIndex+1);
                        animationLeft[heroIndex] = 20;
                        //heroIndex+1
                    }
                    else
                    {
                        if(heroIndex == 5)
                        {
                            copyCard(cards, 2);
                            animationDown[heroIndex] = 20;
                            // 2
                        }
                        else
                        {
                            copyCard(cards, 5);
                            if(heroIndex == 2) animationUp[heroIndex] = 20;
                            else animationDown[heroIndex] = 20;
                            // 5
                        }
                    }
                }
                else if(heroIndex+3 == i)
                {
                    if(heroIndex/3 == 1)
                    {
                        copyCard(cards, heroIndex%3);
                        animationDown[heroIndex] = 20;
                        // heroIndex%3
                    }
                    else
                    {
                        if(heroIndex == 1)
                        {
                            copyCard(cards, 0);
                            animationRight[heroIndex] = 20;
                            // 0
                        }
                        else
                        {
                            copyCard(cards, 1);
                            if(heroIndex == 0) animationLeft[heroIndex] = 20;
                            else animationRight[heroIndex] = 20;
                            // 1
                        }
                    }
                }
                else if(heroIndex-3 == i)
                {
                    if(heroIndex/3 == 1)
                    {
                        copyCard(cards, heroIndex+3);
                        animationUp[heroIndex] = 20;
                        // heroIndex + 3
                    }
                    else
                    {
                        if(heroIndex == 7)
                        {
                            copyCard(cards, 8);
                            animationLeft[heroIndex] = 20;
                            // 8
                        }
                        else
                        {
                            copyCard(cards, 7);
                            if(heroIndex == 8) animationRight[heroIndex] = 20;
                            else animationLeft[heroIndex] = 20;
                            // 7
                        }
                    }
                }

                heroIndex = i;

                std::cout<<"Done!"<<std::endl<<std::endl;
            }
        }
    }
}


void GameEngine::copyCard(Card* cards[9], int index)
{
    std::cout<<" Switch check: ";
    switch(cards[index]->getCardType())
    {
    case card:
        cards[heroIndex] = new Card(*cards[index]);
        break;

    case cardMonster:
        cards[heroIndex] = new CardMonster(*dynamic_cast<CardMonster*>(cards[index]));
        break;

    case cardWeapon:
        cards[heroIndex] = new CardWeapon(*dynamic_cast<CardWeapon*>(cards[index]));
        break;

    case cardTreasure:
        cards[heroIndex] = new CardTreasure(*dynamic_cast<CardTreasure*>(cards[index]));
        break;

    case cardHero:
        break;

    }
    std::cout<<"Done!"<<std::endl;

    std::cout<<" Setting copied card position: ";
    cards[heroIndex]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(index%3), HEIGHT*0.025+HEIGHT*0.325*(index/3));
    std::cout<<"Done!"<<std::endl;

    std::cout<<" Deleting old card: ";
    delete cards[index];
    std::cout<<"Done!"<<std::endl;

    std::cout<<" Creating new card: ";
    createNewCard(cards, index);
    std::cout<<"Done!"<<std::endl;

    animationTime[index] = 30;
}

void GameEngine::doAnimations(Card* cards[9], sf::RectangleShape &weapon)
{
    for(int i = 0; i<9; i++)
    {

        if(animationTime[i]>0)
        {
            cards[i]->cardShape.setScale(1-float(animationTime[i]*0.03), 1-float(animationTime[i]*0.03));
            cards[i]->cardShape.setFillColor(sf::Color(255, 255, 255, 255-animationTime[i]*8));
            cards[i]->cardShape.setRotation(animationTime[i]/2);

            if(i == heroIndex)
            {
                weapon.setScale(1-float(animationTime[i]*0.03), 1-float(animationTime[i]*0.03));
                weapon.setFillColor(sf::Color(255, 255, 255, 255-animationTime[i]*8));
                weapon.setRotation(animationTime[i]/2);
            }

            animationTime[i]--;
            if(animationTime[i]==0)
            {
                weapon.setScale(1, 1);
                cards[i]->cardShape.setScale(1, 1);
            }
        }

        if(animationRight[i]>0)
        {
            cards[i]->cardShape.move(WIDTH*0.13*0.05, 0);

            if(i == heroIndex)
            {
                weapon.move(WIDTH*0.13*0.05, 0);
            }

            animationRight[i]--;
        }

        if(animationLeft[i]>0)
        {
            cards[i]->cardShape.move(-(WIDTH*0.13*0.05), 0);

            if(i == heroIndex)
            {
                weapon.move(-(WIDTH*0.13*0.05), 0);
            }

            animationLeft[i]--;
        }

        if(animationDown[i]>0)
        {
            cards[i]->cardShape.move(0, HEIGHT*0.325*0.05);

            if(i == heroIndex)
            {
                weapon.move(0, HEIGHT*0.325*0.05);
            }

            animationDown[i]--;
        }

        if(animationUp[i]>0)
        {
            cards[i]->cardShape.move(0, -(HEIGHT*0.325*0.05));

            if(i == heroIndex)
            {
                weapon.move(0, -(HEIGHT*0.325*0.05));
            }

            animationUp[i]--;
        }

    }
}

void GameEngine::doAttackAnimations(Card* cards[9], sf::RenderWindow &window)
{
    for(int i = 0; i<9; i++)
    {
        if(animationSword[i]>0)
        {
            sf::RectangleShape swordAttack;
            swordAttack.setSize(sf::Vector2f(WIDTH*0.12, HEIGHT*0.3));
            swordAttack.setOrigin(WIDTH*0.12*0.5, HEIGHT*0.3*0.5);
            swordAttack.setPosition(WIDTH*0.31+WIDTH*0.13*(i%3)+swordAttack.getOrigin().x,
                                    HEIGHT*0.025+HEIGHT*0.325*(i/3)+swordAttack.getOrigin().y);
            swordAttack.setTexture(&texAnimationSword);

            if(animationSword[i]%8>4) swordAttack.setRotation(90);
            else swordAttack.setRotation(0);

            window.draw(swordAttack);
            animationSword[i]--;
        }
        if(animationWandIce[i]>0)
        {
            sf::RectangleShape wandIceAttack;
            wandIceAttack.setSize(sf::Vector2f(WIDTH*0.12, HEIGHT*0.3));
            wandIceAttack.setOrigin(WIDTH*0.12*0.5, HEIGHT*0.3*0.5);
            wandIceAttack.setPosition(WIDTH*0.31+WIDTH*0.13*(i%3)+wandIceAttack.getOrigin().x,
                                      HEIGHT*0.025+HEIGHT*0.325*(i/3)+wandIceAttack.getOrigin().y);
            wandIceAttack.setTexture(&texAnimationWandIce);

            if(animationWandIce[i]%8>4) wandIceAttack.setRotation(90);
            else wandIceAttack.setRotation(0);

            window.draw(wandIceAttack);
            animationWandIce[i]--;
        }
        if(animationChange[i]>0)
        {
            sf::RectangleShape changeShape;
            changeShape.setSize(sf::Vector2f(WIDTH*0.12, HEIGHT*0.3));
            changeShape.setOrigin(WIDTH*0.12*0.5, HEIGHT*0.3*0.5);
            changeShape.setPosition(WIDTH*0.31+WIDTH*0.13*(i%3)+changeShape.getOrigin().x,
                                    HEIGHT*0.025+HEIGHT*0.325*(i/3)+changeShape.getOrigin().y);
            changeShape.setTexture(&texAnimationChange);

            changeShape.rotate(90);

            window.draw(changeShape);
            animationChange[i]--;
        }
    }
}

void GameEngine::drawCards(Card* cards[9], sf::RenderWindow &window, sf::RectangleShape &weapon)
{
    for(int i = 0; i<9; i++)
    {

        window.draw(cards[i]->cardShape);
        cards[i]->drawHp(window);

    }

    if(dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon != none)
    {
        weapon.setSize(sf::Vector2f(WIDTH*0.12*0.5, HEIGHT*0.3*0.7));

        switch(dynamic_cast<CardHero*>(cards[heroIndex])->heroWeapon)
        {
        case sword:
            weapon.setTexture(&texWeaponSword);
            break;
        case wandIce:
            weapon.setTexture(&texWeaponWandIce);
            break;
        case poisonedDagger:
            weapon.setTexture(&texWeaponPoisonedDagger);
            break;
        case none:
            break;
        }

        weapon.setPosition(cards[heroIndex]->cardShape.getPosition().x-WIDTH*0.008,
                           cards[heroIndex]->cardShape.getPosition().y+HEIGHT*0.03);
        window.draw(weapon);
    }
}

void GameEngine::createNewGame(Card* cards[9], Heroes heroType)
{
    isGameOver = false;

    earnedCoins = 0;
    totalSteps = 0;
    heroIndex = 4;
    currentHeroType = heroType;
    switch(heroType)
    {
    case knight:
        panelSkills.setTexture(&texSkillKnight);
        break;
    case mage:
        panelSkills.setTexture(&texSkillMage);
        break;
    case rouge:
        panelSkills.setTexture(&texSkillRouge);
        break;
    }


    cards[heroIndex] = new CardHero(heroType);
    animationTime[heroIndex] = 30;
    cards[heroIndex]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(heroIndex%3), HEIGHT*0.025+HEIGHT*0.325*(heroIndex/3));

    for(int i = 0; i<9; i++)
    {
        if(i != heroIndex)
            createNewCard(cards, i);
    }
}

void GameEngine::shouldTurnIntoRubins(Card* cards[9])
{
    int coinsAmmount = 0;
    for(int i = 0; i<9; i++)
    {
        if(cards[i]->getCardType() == cardTreasure)
        {
            if(dynamic_cast<CardTreasure*>(cards[i])->treasureType == coin)
            {
                coinsAmmount++;
            }
        }
    }

    if(coinsAmmount>=3)
    {
        if(cards[0]->cardShape.getTexture()==cards[1]->cardShape.getTexture() &&
                cards[1]->cardShape.getTexture()==cards[2]->cardShape.getTexture())
            turnIntoRubins(cards, 0, 1, 2);

        if(cards[3]->cardShape.getTexture()==cards[4]->cardShape.getTexture() &&
                cards[4]->cardShape.getTexture()==cards[5]->cardShape.getTexture())
            turnIntoRubins(cards, 3, 4, 5);

        if(cards[6]->cardShape.getTexture()==cards[7]->cardShape.getTexture() &&
                cards[7]->cardShape.getTexture()==cards[8]->cardShape.getTexture())
            turnIntoRubins(cards, 6, 7, 8);

        if(cards[0]->cardShape.getTexture()==cards[3]->cardShape.getTexture() &&
                cards[3]->cardShape.getTexture()==cards[6]->cardShape.getTexture())
            turnIntoRubins(cards, 0, 3, 6);

        if(cards[1]->cardShape.getTexture()==cards[4]->cardShape.getTexture() &&
                cards[4]->cardShape.getTexture()==cards[7]->cardShape.getTexture())
            turnIntoRubins(cards, 1, 4, 7);

        if(cards[2]->cardShape.getTexture()==cards[5]->cardShape.getTexture() &&
                cards[5]->cardShape.getTexture()==cards[8]->cardShape.getTexture())
            turnIntoRubins(cards, 2, 5, 8);

    }
}

void GameEngine::turnIntoRubins(Card* cards[9], int a, int b, int c)
{
    if(Resources::ifAnimationsAreDone())
    {
        soundRubin.play();

        int ammount = 0;

        ammount = dynamic_cast<CardTreasure*>(cards[a])->ammount;
        delete cards[a];
        cards[a] = new CardTreasure(ammount);
        cards[a]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(a%3), HEIGHT*0.025+HEIGHT*0.325*(a/3));

        ammount = dynamic_cast<CardTreasure*>(cards[b])->ammount;
        delete cards[b];
        cards[b] = new CardTreasure(ammount);
        cards[b]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(b%3), HEIGHT*0.025+HEIGHT*0.325*(b/3));

        ammount = dynamic_cast<CardTreasure*>(cards[c])->ammount;
        delete cards[c];
        cards[c] = new CardTreasure(ammount);
        cards[c]->cardShape.setPosition(WIDTH*0.31+WIDTH*0.13*(c%3), HEIGHT*0.025+HEIGHT*0.325*(c/3));
    }
}
