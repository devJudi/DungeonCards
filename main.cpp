#include <iostream>
#include <vector>
#include "Resources.h"
#include "GameEngine.h"
#include "GameWindow.h"
#include "Button.h"
#include "CardMonster.h"
#include "CardHero.h"
#include "CardWeapon.h"
#include "CardTreasure.h"

using namespace std;

sf::Texture texCardTest;
sf::Texture texCardEmpty;

sf::Texture texCardMonsterSkeleton;
sf::Texture texCardMonsterSpider;
sf::Texture texCardMonsterGhost;
sf::Texture texCardMonsterBat;
sf::Texture texCardMonsterZombie;

sf::Texture texCardWeaponSword;
sf::Texture texCardWeaponWandIce;
sf::Texture texCardWeaponPoisonedDagger;
sf::Texture texWeaponSword;
sf::Texture texWeaponWandIce;
sf::Texture texWeaponPoisonedDagger;

sf::Texture texCardTreasureCoin;
sf::Texture texCardTreasureChest;
sf::Texture texCardTreasureHealthPotion;
sf::Texture texCardTreasureDoughnut;
sf::Texture texCardTreasureRubin;

sf::Texture texCardHeroKnight;
sf::Texture texCardHeroMage;
sf::Texture texCardHeroRouge;

sf::Texture texChooseKnight;
sf::Texture texChooseMage;
sf::Texture texChooseRouge;

sf::Texture texLogo;

sf::Texture texInfoBat;
sf::Texture texInfoSkeleton;
sf::Texture texInfoGhost;
sf::Texture texInfoSpider;
sf::Texture texInfoZombie;

sf::Texture texInfoSword;
sf::Texture texInfoWandIce;
sf::Texture texInfoPoisonedDagger;

sf::Texture texInfoChest;
sf::Texture texInfoCoin;
sf::Texture texInfoHealthPotion;
sf::Texture texInfoDoughnut;
sf::Texture texInfoRubin;

sf::Texture texInfoKnight;
sf::Texture texInfoMage;
sf::Texture texInfoRouge;

sf::Texture texInfoEmpty;
sf::Texture texInfoDefault;

sf::Texture texSkillKnight;
sf::Texture texSkillMage;
sf::Texture texSkillRouge;

sf::Texture texAnimationSword;
sf::Texture texAnimationWandIce;
sf::Texture texAnimationChange;

sf::Texture texSoundOn;
sf::Texture texSoundOff;
sf::Texture texMusicOn;
sf::Texture texMusicOff;

sf::Image imageSword;
sf::Image imageWandIce;
sf::Image imagePoisonedDagger;

sf::Font fontPixel;

sf::RectangleShape panelMenu;
sf::RectangleShape panelDetails;
sf::RectangleShape panelGame;
sf::RectangleShape panelGameOver;
sf::RectangleShape panelLogo;
sf::RectangleShape panelInfo;
sf::RectangleShape panelChooseHero;
sf::RectangleShape panelSkills;
sf::RectangleShape panelOptions;
sf::RectangleShape panelShop;

sf::Text textGameOver;
sf::Text textCurrentMoney;
sf::Text textChooseHero;
sf::Text textSkillCooldown;
sf::Text textOptions;

sf::SoundBuffer bufferGameOver;
sf::SoundBuffer bufferWeaponMelee;
sf::SoundBuffer bufferWeaponWand;
sf::SoundBuffer bufferButtonClick;
sf::SoundBuffer bufferZombie;
sf::SoundBuffer bufferSkeleton;
sf::SoundBuffer bufferGhost;
sf::SoundBuffer bufferBat;
sf::SoundBuffer bufferSpider;
sf::SoundBuffer bufferChest;
sf::SoundBuffer bufferPotion;
sf::SoundBuffer bufferDoughnut;
sf::SoundBuffer bufferCoin;
sf::SoundBuffer bufferSkillKnight;
sf::SoundBuffer bufferSkillMage;
sf::SoundBuffer bufferChange;

sf::Sound soundGameOver;
sf::Sound soundWeaponMelee;
sf::Sound soundWeaponWand;
sf::Sound soundButtonClick;
sf::Sound soundZombie;
sf::Sound soundSkeleton;
sf::Sound soundGhost;
sf::Sound soundBat;
sf::Sound soundSpider;
sf::Sound soundChest;
sf::Sound soundPotion;
sf::Sound soundDoughnut;
sf::Sound soundCoin;
sf::Sound soundRubin;
sf::Sound soundSkillKnight;
sf::Sound soundSkillMage;
sf::Sound soundSkillRouge;

sf::Music musicGame;

bool isGameOver;
bool isGameStarted;
bool isOptionsMenuOpen;
bool isShopOpen;

long long int earnedCoins = 0;
long long int totalSteps = 0;
int heroIndex = 4;

int animationTime[9] = {0};
int animationRight[9] = {0};
int animationLeft[9] = {0};
int animationUp[9] = {0};
int animationDown[9] = {0};
int animationSword[9] = {0};
int animationWandIce[9] = {0};
int animationChange[9] = {0};

Heroes currentHeroType;
Buttons currentButton;

Button buttonNewGame(WIDTH*0.2, HEIGHT*0.06, WIDTH*0.15, HEIGHT*0.5, newGame, "NEW GAME", WIDTH*0.105, HEIGHT*0.48);
Button buttonOptions(WIDTH*0.2, HEIGHT*0.06, WIDTH*0.15, HEIGHT*0.6, options, "OPTIONS", WIDTH*0.11, HEIGHT*0.58);
Button buttonQuit(WIDTH*0.2, HEIGHT*0.06, WIDTH*0.15, HEIGHT*0.7, quit, "QUIT GAME", WIDTH*0.098, HEIGHT*0.68);
Button buttonSound(WIDTH*0.1, WIDTH*0.1, WIDTH*0.4, HEIGHT*0.5, sound, "", 0, 0);
Button buttonMusic(WIDTH*0.1, WIDTH*0.1, WIDTH*0.6, HEIGHT*0.5, music, "", 0, 0);

Button buttonShop(WIDTH*0.1, HEIGHT*0.06, WIDTH*0.92, HEIGHT*0.05, shop, "SHOP", WIDTH*0.897, HEIGHT*0.03);
Button buttonBuyHp(WIDTH*0.25, HEIGHT*0.12, WIDTH*0.85, HEIGHT*0.2, buyHp, " MAX HP: +1  \n (100 COINS)", WIDTH*0.73, HEIGHT*0.165);
Button buttonBuyFasterSkills(WIDTH*0.25, HEIGHT*0.12, WIDTH*0.85, HEIGHT*0.35, buyFasterSkills, " SKILL COOLDOWN: -1  \n (125 COINS)", WIDTH*0.73, HEIGHT*0.315);
Button buttonBuySkillImprove(WIDTH*0.25, HEIGHT*0.12, WIDTH*0.85, HEIGHT*0.5, buySkillImprove, " SKILL IMPROVEMENT  \n (150 COINS)", WIDTH*0.73, HEIGHT*0.465);


Button buttonKnight(WIDTH*0.12, HEIGHT*0.3, WIDTH*0.37, HEIGHT*0.55, heroKnight, "", 0, 0);
Button buttonMage(WIDTH*0.12, HEIGHT*0.3, WIDTH*0.50, HEIGHT*0.55, heroMage, "", 0, 0);
Button buttonRouge(WIDTH*0.12, HEIGHT*0.3, WIDTH*0.63, HEIGHT*0.55, heroRouge, "", 0, 0);

int main()
{
    isOptionsMenuOpen = false;

    srand(time(NULL));

    Resources::loadTextures();
    Resources::loadImages();
    Resources::loadFonts();
    Resources::loadPanels();
    Resources::loadTexts();
    Resources::loadSounds();

    buttonKnight.shape.setFillColor(sf::Color::White);
    buttonMage.shape.setFillColor(sf::Color::White);
    buttonRouge.shape.setFillColor(sf::Color::White);

    buttonKnight.shape.setTexture(&texCardHeroKnight);
    buttonMage.shape.setTexture(&texCardHeroMage);
    buttonRouge.shape.setTexture(&texCardHeroRouge);

    buttonSound.shape.setFillColor(sf::Color::White);
    buttonSound.shape.setOutlineColor(sf::Color::Magenta);
    buttonMusic.shape.setFillColor(sf::Color::White);
    buttonMusic.shape.setOutlineColor(sf::Color::Magenta);

    buttonSound.shape.setTexture(&texSoundOn);
    buttonMusic.shape.setTexture(&texMusicOn);

    buttonShop.shape.setOutlineColor(sf::Color(0, 150, 255, 255));
    buttonShop.text.setFillColor(sf::Color(0, 150, 255, 255));

    buttonBuyHp.shape.setOutlineColor(sf::Color(0, 255, 150, 255));
    buttonBuyHp.text.setFillColor(sf::Color(0, 255, 150, 255));

    buttonBuyFasterSkills.shape.setOutlineColor(sf::Color(0, 255, 150, 255));
    buttonBuyFasterSkills.text.setFillColor(sf::Color(0, 255, 150, 255));

    buttonBuySkillImprove.shape.setOutlineColor(sf::Color(0, 255, 150, 255));
    buttonBuySkillImprove.text.setFillColor(sf::Color(0, 255, 150, 255));

    sf::RectangleShape infoButton;
    infoButton.setSize(sf::Vector2f(WIDTH*0.3, HEIGHT*0.27));
    infoButton.setPosition(WIDTH*0.31, HEIGHT*0.71);

    sf::RectangleShape weapon;

    Card* cardSlots[9];

    GameEngine::createNewGame(cardSlots, knight);

    GameWindow window(WIDTH, HEIGHT, "alpha 0.4");

    isGameStarted = false;
    isGameOver = false;

    musicGame.setVolume(50);
    musicGame.setLoop(true);
    musicGame.play();

    while(window.isOpen())
    {
        if(buttonMusic.shape.getTexture() == &texMusicOn)
        {
            if(isGameStarted) musicGame.setVolume(30);
            else musicGame.setVolume(60);
        }
        else musicGame.setVolume(0);


        window.handleEvents(cardSlots, dynamic_cast<CardHero*>(cardSlots[heroIndex]));

        if(!isOptionsMenuOpen && isGameStarted)
        {
            GameEngine::shouldTurnIntoRubins(cardSlots);
            GameEngine::moveCards(cardSlots);
            GameEngine::doAnimations(cardSlots, weapon);
        }

        window.clear();

        window.draw(panelMenu);
        window.draw(panelDetails);
        window.draw(panelGame);
        window.draw(panelLogo);
        window.draw(panelInfo);

        window.draw(buttonQuit.shape);
        window.draw(buttonQuit.text);
        window.draw(buttonOptions.shape);
        window.draw(buttonOptions.text);
        window.draw(buttonNewGame.shape);
        window.draw(buttonNewGame.text);
        window.draw(buttonShop.shape);
        window.draw(buttonShop.text);

        if(isGameStarted)
        {
            bool isNoInfo = true;
            for(int i = 0; i<9; i++)
            {
                if(cardSlots[i]->showInfo)
                {
                    window.draw(cardSlots[i]->infoShape);
                    isNoInfo = false;
                }
            }
            if(isNoInfo)
            {
                sf::RectangleShape infoShape;
                infoShape.setSize(sf::Vector2f(WIDTH*0.3-10, HEIGHT*0.5-10));
                infoShape.setPosition(WIDTH*0.7+5, HEIGHT*0.1+5);
                infoShape.setTexture(&texInfoDefault);

                window.draw(infoShape);
            }

            if(isShopOpen)
            {
                window.draw(panelShop);
                window.draw(buttonBuyHp.shape);
                window.draw(buttonBuyHp.text);
                window.draw(buttonBuyFasterSkills.shape);
                window.draw(buttonBuyFasterSkills.text);
                window.draw(buttonBuySkillImprove.shape);
                window.draw(buttonBuySkillImprove.text);
            }
        }



        GameEngine::drawCards(cardSlots, window, weapon);
        GameEngine::doAttackAnimations(cardSlots, window);
        if(!isGameStarted)
        {
            window.draw(panelChooseHero);
            window.draw(textChooseHero);
            window.draw(buttonKnight.shape);
            window.draw(buttonMage.shape);
            window.draw(buttonRouge.shape);

            switch(currentButton)
            {
            case heroKnight:
                infoButton.setTexture(&texChooseKnight);
                window.draw(infoButton);
                break;
            case heroMage:
                infoButton.setTexture(&texChooseMage);
                window.draw(infoButton);
                break;
            case heroRouge:
                infoButton.setTexture(&texChooseRouge);
                window.draw(infoButton);
                break;
            default:
                break;
            }
        }

        if(isGameStarted)
        {
            window.draw(panelSkills);

            textCurrentMoney.setString("COINS: " + std::to_string(earnedCoins));
            window.draw(textCurrentMoney);

            int skillCoolDownTime = dynamic_cast<CardHero*>(cardSlots[heroIndex])->skillCooldown - dynamic_cast<CardHero*>(cardSlots[heroIndex])->currentCooldown;
            textSkillCooldown.setString("SKILL COOLDOWN: " + std::to_string(skillCoolDownTime));
            window.draw(textSkillCooldown);
        }

        if(isGameOver)
        {
            window.draw(panelGameOver);
            window.draw(textGameOver);
        }

        if(isOptionsMenuOpen)
        {
            window.draw(panelOptions);
            window.draw(textOptions);
            window.draw(buttonSound.shape);
            window.draw(buttonMusic.shape);
        }

        window.display();
    }
    cout<<totalSteps<<endl;
    return 0;
}
