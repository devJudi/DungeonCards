#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Card.h"
#include "CardWeapon.h"
#include "CardHero.h"
#include "CardMonster.h"
#include "CardTreasure.h"
#include <SFML/Graphics.hpp>

extern int animationTime[9];
extern int animationRight[9];
extern int animationLeft[9];
extern int animationDown[9];
extern int animationUp[9];
extern int animationSword[9];
extern int animationWandIce[9];
extern int animationChange[9];

extern sf::Texture texWeaponSword;
extern sf::Texture texWeaponWandIce;

extern sf::Texture texAnimationSword;
extern sf::Texture texAnimationWandIce;

extern sf::Sound soundRubin;

extern long long int earnedCoins;
extern int heroIndex;
extern bool isGameOver;

extern Heroes currentHeroType;

class GameEngine
{
    public:
        GameEngine();

        static void createNewCard(Card* cards[9], int number);
        static void moveCards(Card* cards[9]);
        static void copyCard(Card* cards[9], int index);
        static void doAnimations(Card* cards[9], sf::RectangleShape &weapon);
        static void doAttackAnimations(Card* cards[9], sf::RenderWindow &window);
        static void drawCards(Card* cards[9], sf::RenderWindow &window, sf::RectangleShape &weapon);
        static void createNewGame(Card* cards[9], Heroes heroType);
        static void shouldTurnIntoRubins(Card* cards[9]);
        static void turnIntoRubins(Card* cards[9], int a, int b, int c);

        virtual ~GameEngine();

    protected:

    private:
};

#endif // GAMEENGINE_H
