#include "GameWindow.h"

GameWindow::GameWindow(int x, int y, std::string name, int fps)
{
    this->create(sf::VideoMode(x, y), name, sf::Style::Fullscreen);
    this->setFramerateLimit(fps);
}

GameWindow::~GameWindow()
{
    //dtor
}

void GameWindow::handleEvents(Card* cards[9], CardHero* hero)
{
    sf::Event event;
    while(this->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            this->close();
        }
        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
            {
                this->close();
            }
        }
        if(event.type == sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*this);

                buttonQuit.onClick(mousePos, *this, cards);
                buttonNewGame.onClick(mousePos, *this, cards);
                buttonOptions.onClick(mousePos, *this, cards);
                buttonShop.onClick(mousePos, *this, cards);
                if(isOptionsMenuOpen)
                {
                    buttonSound.onClick(mousePos, *this, cards);
                    buttonMusic.onClick(mousePos, *this, cards);
                }

                else if(!isGameStarted)
                {
                    buttonKnight.onClick(mousePos, *this, cards);
                    buttonMage.onClick(mousePos, *this, cards);
                    buttonRouge.onClick(mousePos, *this, cards);

                }
                if(isShopOpen)
                {
                    buttonBuyHp.onClick(mousePos, *this, cards);
                    buttonBuyFasterSkills.onClick(mousePos, *this, cards);
                    buttonBuySkillImprove.onClick(mousePos, *this, cards);
                }

                if(!isGameOver && !isOptionsMenuOpen)
                {
                    for(int i = 0; i<9; i++)
                    {
                        if(Resources::ifAnimationsAreDone() == true)
                        {
                            if(cards[i]->mouseClicked(mousePos, cards, hero)) break;
                        }
                    }
                }

            }
            else if(event.mouseButton.button == sf::Mouse::Right)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*this);

                if(!isGameOver && !isOptionsMenuOpen)
                {
                    for(int i = 0; i<9; i++)
                    {
                        if(Resources::ifAnimationsAreDone() == true)
                        {
                            cards[i]->checkIfShowInfo(mousePos);
                        }
                    }
                }
            }
        }
        if(event.type == sf::Event::MouseMoved)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*this);
            buttonQuit.onMouseEntered(mousePos, *this);
            buttonNewGame.onMouseEntered(mousePos, *this);
            buttonOptions.onMouseEntered(mousePos, *this);
            buttonShop.onMouseEntered(mousePos, *this);
            if(!isGameStarted && !isOptionsMenuOpen)
            {
                buttonKnight.onMouseEntered(mousePos, *this);
                buttonMage.onMouseEntered(mousePos, *this);
                buttonRouge.onMouseEntered(mousePos, *this);
            }
            else if(isShopOpen)
            {
                buttonBuyHp.onMouseEntered(mousePos, *this);
                buttonBuyFasterSkills.onMouseEntered(mousePos, *this);
                buttonBuySkillImprove.onMouseEntered(mousePos, *this);
            }

        }
    }
}
