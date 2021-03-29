#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Resources.h"

class CardHero;

extern sf::Texture texCardEmpty;
extern sf::Texture texInfoEmpty;

extern bool shouldBeDeleted[9];

extern long long int totalSteps;

enum CardTypes
{
    card = 0,
    cardMonster,
    cardHero,
    cardWeapon,
    cardTreasure
};

class Card
{
    public:
        Card();
        sf::RectangleShape cardShape;
        void checkIfShowInfo(sf::Vector2i mousePos);
        virtual void drawHp(sf::RenderWindow &window);
        virtual bool mouseClicked(sf::Vector2i mousePos, Card* cards[9], CardHero* hero);
        virtual CardTypes getCardType();
        virtual ~Card();

        bool deleteMe;
        bool showInfo;
        sf::RectangleShape infoShape;

    protected:

    private:
};

#endif // CARD_H
