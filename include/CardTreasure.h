#ifndef CARDTREASURE_H
#define CARDTREASURE_H

#include "CardHero.h"

extern sf::Texture texCardTreasureCoin;
extern sf::Texture texCardTreasureChest;
extern sf::Texture texCardTreasureHealthPotion;
extern sf::Texture texCardTreasureRubin;

extern sf::Texture texInfoCoin;
extern sf::Texture texInfoChest;
extern sf::Texture texInfoHealthPotion;
extern sf::Texture texInfoDoughnut;
extern sf::Texture texInfoRubin;

extern sf::Sound soundChest;
extern sf::Sound soundPotion;
extern sf::Sound soundDoughnut;
extern sf::Sound soundCoin;

extern long long int earnedCoins;
extern Heroes currentHeroType;


enum Treasures
{
    coin = 0,
    rubin,
    chest,
    healthPotion
};

class CardTreasure : public Card
{
    public:
        CardTreasure();
        CardTreasure(int rubins);
        CardTreasure(Treasures type);
        CardTreasure(const CardTreasure &copiedCard);
        void drawHp(sf::RenderWindow &window);
        void doAction(CardHero* hero);
        bool mouseClicked(sf::Vector2i mousePos, Card* cards[9], CardHero* hero);
        CardTypes getCardType();
        void setCardGraphics();
        virtual ~CardTreasure();

        int ammount;
        Treasures treasureType;

    protected:

    private:
};

#endif // CARDTREASURE_H

