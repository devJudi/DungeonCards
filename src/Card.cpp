#include "Card.h"

Card::Card()
{
    cardShape.setSize(sf::Vector2f(WIDTH*0.12, HEIGHT*0.3));
    cardShape.setTexture(&texCardEmpty);

    infoShape.setSize(sf::Vector2f(WIDTH*0.3-10, HEIGHT*0.5-10));
    infoShape.setPosition(WIDTH*0.7+5, HEIGHT*0.1+5);
    infoShape.setTexture(&texInfoEmpty);

    deleteMe = false;
    showInfo = false;
}

Card::~Card()
{
    //dtor
}
//void Card::doAction()
//{
//    std::cout<<"heheh"<<std::endl;
//}

void Card::drawHp(sf::RenderWindow &window)
{
    //std::cout<<"heheh"<<std::endl;
    return;
}

CardTypes Card::getCardType()
{
    return card;
}

void Card::checkIfShowInfo(sf::Vector2i mousePos)
{
    if(mousePos.x >= cardShape.getPosition().x &&
       mousePos.x <= cardShape.getPosition().x + cardShape.getSize().x &&
       mousePos.y >= cardShape.getPosition().y  &&
       mousePos.y <= cardShape.getPosition().y + cardShape.getSize().y)
    {
        showInfo = true;
    }
    else
    {
        showInfo = false;
    }
}
