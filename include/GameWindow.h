#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <algorithm>
#include <SFML/Graphics.hpp>
#include "CardHero.h"
#include "Button.h"

extern bool isGameOver;

extern int animationTime[9];
extern int animationRight[9];
extern int animationLeft[9];
extern int animationDown[9];
extern int animationUp[9];

extern Button buttonQuit;
extern Button buttonNewGame;
extern Button buttonOptions;
extern Button buttonSound;
extern Button buttonMusic;
extern Button buttonShop;
extern Button buttonBuyHp;
extern Button buttonBuyFasterSkills;
extern Button buttonBuySkillImprove;
extern Button buttonKnight;
extern Button buttonMage;
extern Button buttonRouge;

extern bool isGameStarted;
extern bool isOptionsMenuOpen;
extern bool isShopOpen;

class GameWindow : public sf::RenderWindow
{
    public:
        GameWindow(int x, int y, std::string name, int fps = 60);
        void handleEvents(Card* cards[9], CardHero* hero);
        virtual ~GameWindow();

    protected:

    private:
};

#endif // GAMEWINDOW_H
