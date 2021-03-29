#ifndef CARDMONSTER_H
#define CARDMONSTER_H

#include <iostream>
#include <stdlib.h>
#include "CardHero.h"
#include "CardWeapon.h"
#include "CardTreasure.h"

extern sf::Texture texCardTest;
extern sf::Texture texCardMonsterSkeleton;
extern sf::Texture texCardMonsterSpider;
extern sf::Texture texCardMonsterGhost;
extern sf::Texture texCardMonsterBat;
extern sf::Texture texCardMonsterZombie;

extern sf::Texture texInfoSkeleton;
extern sf::Texture texInfoSpider;
extern sf::Texture texInfoGhost;
extern sf::Texture texInfoBat;
extern sf::Texture texInfoZombie;

extern sf::Font fontPixel;

extern sf::Sound soundZombie;
extern sf::Sound soundSkeleton;
extern sf::Sound soundGhost;
extern sf::Sound soundBat;
extern sf::Sound soundSpider;

extern sf::Sound soundSkillKnight;
extern sf::Sound soundSkillMage;
extern sf::Sound soundSkillRouge;

extern int animationSword[9];
extern int animationWandIce[9];
extern int animationChange[9];
extern int heroIndex;

enum Monsters
{
    zombie = 0,
    skeleton,
    ghost,
    spider,
    bat
};

class CardMonster : public Card
{
    public:
        CardMonster();
        CardMonster(const CardMonster &copiedCard);
        void doAction(Card* cards[9], CardHero* hero);
        bool mouseClicked(sf::Vector2i mousePos, Card* cards[9], CardHero* hero);
        void drawHp(sf::RenderWindow &window);
        CardTypes getCardType();
        void setCardGraphics();
        virtual ~CardMonster();

        Monsters monsterType;
        int hp;
        int fullHp;
        int lastDamage;

    protected:

    private:
};

#endif // CARDMONSTER_H
