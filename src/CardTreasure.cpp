#include "CardTreasure.h"

CardTreasure::CardTreasure()
    :Card()
{
    int random = rand()%6;
    if(random == 0 || random == 1) treasureType = chest;
    else if(random == 2) treasureType = healthPotion;
    else treasureType = coin;

    this->setCardGraphics();
}

CardTreasure::CardTreasure(int rubins)
    :Card()
{
    treasureType = rubin;
    this->setCardGraphics();
    ammount = rubins*2;
}

CardTreasure::CardTreasure(Treasures type)
    :Card()
{
    treasureType = type;
    this->setCardGraphics();
}

CardTreasure::CardTreasure(const CardTreasure &copiedCard)
{
    treasureType = copiedCard.treasureType;
    this->setCardGraphics();
    ammount = copiedCard.ammount;
    showInfo = copiedCard.showInfo;
}

CardTreasure::~CardTreasure()
{
    //dtor
}

void CardTreasure::drawHp(sf::RenderWindow &window)
{
    sf::Text text;

    int offset = 0;
    if(ammount<-99||ammount>99) offset = 2;
    else if(ammount<-9||ammount>9) offset = 1;
    else offset = 0;
    if(ammount<0) offset++;

    text.setString(std::to_string(ammount));
    if(ammount == 0) text.setString(" ");
    text.setFillColor(sf::Color::Red);
    text.setFont(fontPixel);
    text.setPosition(cardShape.getPosition().x+WIDTH*0.1-offset*WIDTH*0.01, cardShape.getPosition().y+HEIGHT*0.01);
    text.setCharacterSize(WIDTH*0.02);

    window.draw(text);
}

void CardTreasure::doAction(CardHero* hero)
{
    switch(treasureType)
    {
    case coin:
        earnedCoins+=ammount;
        deleteMe = true;
        soundCoin.play();
        break;

    case rubin:
        earnedCoins+=ammount;
        deleteMe = true;
        soundCoin.play();
        break;

    case chest:
        deleteMe = true;
        soundChest.play();
        break;

    case healthPotion:
        if(ammount+hero->hp > hero->maxHp) hero->hp = hero->maxHp;
        else hero->hp+=ammount;
        deleteMe = true;
        if(hero->heroType == rouge) soundDoughnut.play();
        else soundPotion.play();
        break;
    }
}

bool CardTreasure::mouseClicked(sf::Vector2i mousePos, Card* cards[9], CardHero* hero)
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
                doAction(hero);
                totalSteps++;
            }
        }
        else if(y == heroY)
        {
            if((x-heroX)!=2 && (heroX-x)!=2)
            {
                doAction(hero);
                totalSteps++;
            }
        }
        else std::cout<<"Invalid target!"<<std::endl;

        return true;
    }
    else return false;
}

CardTypes CardTreasure::getCardType()
{
    return cardTreasure;
}

void CardTreasure::setCardGraphics()
{
    switch(treasureType)
    {
    case coin:
        cardShape.setTexture(&texCardTreasureCoin);
        infoShape.setTexture(&texInfoCoin);
        ammount = 2 + rand()%8;
        break;

    case rubin:
        cardShape.setTexture(&texCardTreasureRubin);
        infoShape.setTexture(&texInfoRubin);
        ammount = 0;
        break;

    case chest:
        cardShape.setTexture(&texCardTreasureChest);
        infoShape.setTexture(&texInfoChest);
        ammount = 0;
        break;

    case healthPotion:
        if(currentHeroType == rouge)
        {
            cardShape.setTexture(&texCardTreasureDoughnut);
            infoShape.setTexture(&texInfoDoughnut);

        }
        else
        {
            cardShape.setTexture(&texCardTreasureHealthPotion);
            infoShape.setTexture(&texInfoHealthPotion);
        }

        ammount = 1 + rand()%5;
        break;
    }
}
