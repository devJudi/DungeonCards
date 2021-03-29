#include "Button.h"

Button::Button(int x, int y, int posX, int posY, Buttons type, std::string name, int textX, int textY)
{
    shape.setSize(sf::Vector2f(x, y));
    shape.setPosition(posX, posY);
    shape.setOutlineThickness(-4);
    shape.setOutlineColor(sf::Color::Blue);
    shape.setFillColor(sf::Color::Black);
    shape.setOrigin(x/2, y/2);

    text.setString(name);
    text.setCharacterSize(WIDTH*0.02);
    text.setPosition(textX, textY);
    text.setFillColor(sf::Color::Blue);
    text.setFont(fontPixel);

    buttonType = type;
}

Button::~Button()
{
    //dtor
}

void Button::onClick(sf::Vector2i mousePos, sf::RenderWindow &window, Card* cards[9])
{
    if(mousePos.x >= shape.getPosition().x - shape.getSize().x/2 &&
       mousePos.x <= shape.getPosition().x + shape.getSize().x/2 &&
       mousePos.y >= shape.getPosition().y - shape.getSize().y/2 &&
       mousePos.y <= shape.getPosition().y + shape.getSize().y/2)
    {
        soundButtonClick.play();

        switch(buttonType)
        {
        case newGame:
            isGameOver = false;
            isGameStarted = false;
            earnedCoins = 0;
            break;

        case options:
            if(!isOptionsMenuOpen) isOptionsMenuOpen = true;
            else isOptionsMenuOpen = false;
            break;

        case sound:
            if(shape.getTexture()==&texSoundOn)
            {
                Resources::soundOff();
                shape.setTexture(&texSoundOff);
            }
            else
            {
                Resources::soundOn();
                shape.setTexture(&texSoundOn);

            }
            break;

        case music:
            if(shape.getTexture()==&texMusicOn) shape.setTexture(&texMusicOff);
            else shape.setTexture(&texMusicOn);
            break;

        case quit:
            window.close();
            break;

        case shop:
            if(!isShopOpen) isShopOpen = true;
            else isShopOpen = false;
            break;

        case buyHp:
            dynamic_cast<CardHero*>(cards[heroIndex])->increasceHp();
            break;

        case buyFasterSkills:
            dynamic_cast<CardHero*>(cards[heroIndex])->decreasceSkillCooldown();
            break;

        case buySkillImprove:
            dynamic_cast<CardHero*>(cards[heroIndex])->improveSkill();
            break;

        case heroKnight:
            GameEngine::createNewGame(cards, knight);
            isGameStarted = true;
            break;

        case heroMage:
            GameEngine::createNewGame(cards, mage);
            isGameStarted = true;
            break;

        case heroRouge:
            GameEngine::createNewGame(cards, rouge);
            isGameStarted = true;
            break;
        }
    }

}

void Button::onMouseEntered(sf::Vector2i mousePos, sf::RenderWindow &window)
{
    if(mousePos.x >= shape.getPosition().x - shape.getSize().x/2 &&
       mousePos.x <= shape.getPosition().x + shape.getSize().x/2 &&
       mousePos.y >= shape.getPosition().y - shape.getSize().y/2 &&
       mousePos.y <= shape.getPosition().y + shape.getSize().y/2)
    {
        shape.setScale(0.9, 0.9);

        if(buttonType == shop) text.setFillColor(sf::Color(0, 255, 255, 255));
        else if(buttonType == buyHp || buttonType == buyFasterSkills || buttonType == buySkillImprove) text.setFillColor(sf::Color(0, 255, 30, 255));
        else text.setFillColor(sf::Color(100, 100, 255, 255));

        currentButton = buttonType;
    }
    else
    {
        if(currentButton == buttonType)
            currentButton = quit;

        shape.setScale(1, 1);

        if(buttonType == shop) text.setFillColor(sf::Color(0, 150, 255, 255));
        else if(buttonType == buyHp || buttonType == buyFasterSkills || buttonType == buySkillImprove) text.setFillColor(sf::Color(0, 255, 150, 255));
        else text.setFillColor(sf::Color::Blue);
    }
}
