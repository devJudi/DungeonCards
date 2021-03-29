#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include "GameEngine.h"
#include "Resources.h"

extern sf::Font fontPixel;

extern sf::Sound soundButtonClick;

extern bool isGameOver;
extern bool isGameStarted;
extern bool isOptionsMenuOpen;
extern bool isShopOpen;

extern int heroIndex;

enum Buttons
{
    newGame = 0,
    quit,
    options,
    sound,
    music,
    shop,
    buyHp,
    buyFasterSkills,
    buySkillImprove,
    heroKnight,
    heroMage,
    heroRouge
};

extern Buttons currentButton;

class Button
{
    public:
        Button(int x, int y, int posX, int posY, Buttons type, std::string name, int textX, int textY);
        void onClick(sf::Vector2i mousePos, sf::RenderWindow &window, Card* cards[9]);
        void onMouseEntered(sf::Vector2i mousePos, sf::RenderWindow &window);
        virtual ~Button();

        sf::RectangleShape shape;
        sf::Text text;
        Buttons buttonType;
    protected:

    private:
};

#endif // BUTTON_H
