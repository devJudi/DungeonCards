#ifndef RESOURCES_H
#define RESOURCES_H

#define WIDTH sf::VideoMode::getDesktopMode().width
#define HEIGHT sf::VideoMode::getDesktopMode().height

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

extern sf::Texture texCardTest;
extern sf::Texture texCardEmpty;

extern sf::Texture texCardMonsterSkeleton;
extern sf::Texture texCardMonsterSpider;
extern sf::Texture texCardMonsterGhost;
extern sf::Texture texCardMonsterBat;
extern sf::Texture texCardMonsterZombie;

extern sf::Texture texCardWeaponSword;
extern sf::Texture texCardWeaponWandIce;
extern sf::Texture texCardWeaponPoisonedDagger;
extern sf::Texture texWeaponSword;
extern sf::Texture texWeaponWandIce;
extern sf::Texture texWeaponPoisonedDagger;

extern sf::Texture texCardTreasureCoin;
extern sf::Texture texCardTreasureChest;
extern sf::Texture texCardTreasureHealthPotion;
extern sf::Texture texCardTreasureDoughnut;
extern sf::Texture texCardTreasureRubin;

extern sf::Texture texCardHeroKnight;
extern sf::Texture texCardHeroMage;
extern sf::Texture texCardHeroRouge;

extern sf::Texture texLogo;

extern sf::Texture texInfoBat;
extern sf::Texture texInfoSkeleton;
extern sf::Texture texInfoGhost;
extern sf::Texture texInfoSpider;
extern sf::Texture texInfoZombie;

extern sf::Texture texInfoSword;
extern sf::Texture texInfoWandIce;
extern sf::Texture texInfoPoisonedDagger;

extern sf::Texture texInfoChest;
extern sf::Texture texInfoCoin;
extern sf::Texture texInfoHealthPotion;
extern sf::Texture texInfoDoughnut;
extern sf::Texture texInfoRubin;

extern sf::Texture texInfoKnight;
extern sf::Texture texInfoMage;
extern sf::Texture texInfoRouge;

extern sf::Texture texChooseKnight;
extern sf::Texture texChooseMage;
extern sf::Texture texChooseRouge;

extern sf::Texture texInfoEmpty;
extern sf::Texture texInfoDefault;

extern sf::Texture texSkillKnight;
extern sf::Texture texSkillMage;
extern sf::Texture texSkillRouge;

extern sf::Texture texAnimationSword;
extern sf::Texture texAnimationWandIce;
extern sf::Texture texAnimationChange;

extern sf::Texture texSoundOn;
extern sf::Texture texSoundOff;
extern sf::Texture texMusicOn;
extern sf::Texture texMusicOff;

extern sf::Image imageSword;
extern sf::Image imageWandIce;
extern sf::Image imagePoisonedDagger;

extern sf::Font fontPixel;

extern sf::RectangleShape panelMenu;
extern sf::RectangleShape panelDetails;
extern sf::RectangleShape panelGame;
extern sf::RectangleShape panelGameOver;
extern sf::RectangleShape panelLogo;
extern sf::RectangleShape panelInfo;
extern sf::RectangleShape panelChooseHero;
extern sf::RectangleShape panelSkills;
extern sf::RectangleShape panelOptions;
extern sf::RectangleShape panelShop;

extern sf::Text textGameOver;
extern sf::Text textCurrentMoney;
extern sf::Text textChooseHero;
extern sf::Text textSkillCooldown;
extern sf::Text textOptions;

extern sf::SoundBuffer bufferGameOver;
extern sf::SoundBuffer bufferWeaponMelee;
extern sf::SoundBuffer bufferWeaponWand;
extern sf::SoundBuffer bufferButtonClick;
extern sf::SoundBuffer bufferZombie;
extern sf::SoundBuffer bufferSkeleton;
extern sf::SoundBuffer bufferGhost;
extern sf::SoundBuffer bufferBat;
extern sf::SoundBuffer bufferSpider;
extern sf::SoundBuffer bufferChest;
extern sf::SoundBuffer bufferPotion;
extern sf::SoundBuffer bufferDoughnut;
extern sf::SoundBuffer bufferCoin;
extern sf::SoundBuffer bufferSkillKnight;
extern sf::SoundBuffer bufferSkillMage;
extern sf::SoundBuffer bufferChange;

extern sf::Sound soundGameOver;
extern sf::Sound soundWeaponMelee;
extern sf::Sound soundWeaponWand;
extern sf::Sound soundButtonClick;
extern sf::Sound soundZombie;
extern sf::Sound soundSkeleton;
extern sf::Sound soundGhost;
extern sf::Sound soundBat;
extern sf::Sound soundSpider;
extern sf::Sound soundChest;
extern sf::Sound soundPotion;
extern sf::Sound soundDoughnut;
extern sf::Sound soundCoin;
extern sf::Sound soundRubin;
extern sf::Sound soundSkillKnight;
extern sf::Sound soundSkillMage;
extern sf::Sound soundSkillRouge;

extern sf::Music musicGame;

extern int animationTime[9];
extern int animationRight[9];
extern int animationLeft[9];
extern int animationDown[9];
extern int animationUp[9];

class Resources
{
    public:
        Resources();
        static void loadTextures();
        static void loadFonts();
        static void loadImages();
        static void loadPanels();
        static void loadTexts();
        static void loadSounds();

        static void soundOff();
        static void soundOn();

        static bool ifAnimationsAreDone();
        virtual ~Resources();

    protected:

    private:
};

#endif // RESOURCES_H
