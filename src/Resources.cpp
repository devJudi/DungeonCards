#include "Resources.h"

Resources::Resources()
{
    //ctor
}

Resources::~Resources()
{
    //dtor
}

void Resources::loadTextures()
{
    texCardTest.loadFromFile("img/cardTest.png");
    texCardEmpty.loadFromFile("img/cardEmpty.png");

    texCardMonsterBat.loadFromFile("img/cardMonsterBat.png");
    texCardMonsterGhost.loadFromFile("img/cardMonsterGhost.png");
    texCardMonsterSkeleton.loadFromFile("img/cardMonsterSkeleton.png");
    texCardMonsterSpider.loadFromFile("img/cardMonsterSpider.png");
    texCardMonsterZombie.loadFromFile("img/cardMonsterZombie.png");

    texCardWeaponSword.loadFromFile("img/cardWeaponSword.png");
    texCardWeaponWandIce.loadFromFile("img/cardWeaponWandIce.png");
    texCardWeaponPoisonedDagger.loadFromFile("img/cardWeaponPoisonedDagger.png");

    texCardTreasureCoin.loadFromFile("img/cardTreasureCoins.png");
    texCardTreasureChest.loadFromFile("img/cardTreasureChest.png");
    texCardTreasureHealthPotion.loadFromFile("img/cardTreasureHealthPotion.png");
    texCardTreasureDoughnut.loadFromFile("img/cardTreasureDoughnut.png");
    texCardTreasureRubin.loadFromFile("img/cardTreasureRubin.png");

    texCardHeroKnight.loadFromFile("img/cardHeroKnight.png");
    texCardHeroMage.loadFromFile("img/cardHeroMage.png");
    texCardHeroRouge.loadFromFile("img/cardHeroRouge.png");

    texChooseKnight.loadFromFile("img/heroes/chooseKnight.png");
    texChooseMage.loadFromFile("img/heroes/chooseMage.png");
    texChooseRouge.loadFromFile("img/heroes/chooseRouge.png");

    texLogo.loadFromFile("img/others/logo2.png");

    texInfoBat.loadFromFile("img/info/mobs/infoBat.png");
    texInfoZombie.loadFromFile("img/info/mobs/infoZombie.png");
    texInfoGhost.loadFromFile("img/info/mobs/infoGhost.png");
    texInfoSpider.loadFromFile("img/info/mobs/infoSpider.png");
    texInfoSkeleton.loadFromFile("img/info/mobs/infoSkeleton.png");

    texInfoSword.loadFromFile("img/info/weapons/infoSword.png");
    texInfoWandIce.loadFromFile("img/info/weapons/infoWandIce.png");
    texInfoPoisonedDagger.loadFromFile("img/info/weapons/infoPoisonedDagger.png");

    texInfoChest.loadFromFile("img/info/treasures/infoChest.png");
    texInfoCoin.loadFromFile("img/info/treasures/infoCoin.png");
    texInfoHealthPotion.loadFromFile("img/info/treasures/infoHealthPotion.png");
    texInfoDoughnut.loadFromFile("img/info/treasures/infoDoughnut.png");
    texInfoRubin.loadFromFile("img/info/treasures/infoRubin.png");

    texInfoKnight.loadFromFile("img/info/heroes/infoKnight.png");
    texInfoMage.loadFromFile("img/info/heroes/infoMage.png");
    texInfoRouge.loadFromFile("img/info/heroes/infoRouge.png");

    texInfoEmpty.loadFromFile("img/info/infoEmpty.png");
    texInfoDefault.loadFromFile("img/info/infoDefault.png");

    texSkillKnight.loadFromFile("img/skills/skillKnight.png");
    texSkillMage.loadFromFile("img/skills/skillMage.png");
    texSkillRouge.loadFromFile("img/skills/skillRouge.png");

    texAnimationSword.loadFromFile("img/animations/animationSword.png");
    texAnimationWandIce.loadFromFile("img/animations/animationWandIce.png");
    texAnimationChange.loadFromFile("img/animations/animationChange.png");

    texSoundOn.loadFromFile("img/others/soundIcon.png");
    texSoundOff.loadFromFile("img/others/disabledSoundIcon.png");
    texMusicOn.loadFromFile("img/others/musicIcon.png");
    texMusicOff.loadFromFile("img/others/disabledMusicIcon.png");
}

void Resources::loadFonts()
{
    fontPixel.loadFromFile("fonts/fontPixel.ttf");
}

void Resources::loadImages()
{
    imageSword.loadFromFile("img/weapons/sword.png");
    imageSword.createMaskFromColor(sf::Color::Black);
    texWeaponSword.loadFromImage(imageSword);

    imageWandIce.loadFromFile("img/weapons/wandIce.png");
    imageWandIce.createMaskFromColor(sf::Color::Black);
    texWeaponWandIce.loadFromImage(imageWandIce);

    imagePoisonedDagger.loadFromFile("img/weapons/poisonedDagger.png");
    imagePoisonedDagger.createMaskFromColor(sf::Color::Black);
    texWeaponPoisonedDagger.loadFromImage(imagePoisonedDagger);
}
void Resources::loadPanels()
{
    panelMenu.setSize(sf::Vector2f(WIDTH*0.3, HEIGHT));
    panelMenu.setOutlineThickness(-3);
    panelMenu.setOutlineColor(sf::Color::Blue);
    panelMenu.setFillColor(sf::Color::Black);
    panelMenu.setPosition(0, 0);

    panelDetails.setSize(sf::Vector2f(WIDTH*0.3, HEIGHT));
    panelDetails.setOutlineThickness(-3);
    panelDetails.setOutlineColor(sf::Color::Blue);
    panelDetails.setFillColor(sf::Color::Black);
    panelDetails.setPosition(WIDTH*0.7, 0);

    panelGame.setSize(sf::Vector2f(WIDTH*0.4, HEIGHT));
    panelGame.setOutlineThickness(-3);
    panelGame.setOutlineColor(sf::Color::Blue);
    panelGame.setFillColor(sf::Color::Black);
    panelGame.setPosition(WIDTH*0.3, 0);

    panelGameOver.setSize(sf::Vector2f(WIDTH*0.4, HEIGHT));
    panelGameOver.setOutlineThickness(-10);
    panelGameOver.setOutlineColor(sf::Color::Magenta);
    panelGameOver.setFillColor(sf::Color(0, 0, 0, 180));
    panelGameOver.setPosition(WIDTH*0.3, 0);

    panelLogo.setSize(sf::Vector2f(WIDTH*0.3-6, WIDTH*0.1875-6));
    panelLogo.setOutlineThickness(0);
    panelLogo.setOutlineColor(sf::Color::Blue);
    panelLogo.setPosition(3, 3);
    panelLogo.setTexture(&texLogo);

    panelInfo.setSize(sf::Vector2f(WIDTH*0.3, HEIGHT*0.5));
    panelInfo.setOutlineThickness(-5);
    panelInfo.setOutlineColor(sf::Color::Blue);
    panelInfo.setPosition(WIDTH*0.7, HEIGHT*0.1);
    panelInfo.setFillColor(sf::Color::Black);

    panelChooseHero.setSize(sf::Vector2f(WIDTH*0.4, HEIGHT));
    panelChooseHero.setOutlineThickness(-5);
    panelChooseHero.setOutlineColor(sf::Color::Blue);
    panelChooseHero.setPosition(WIDTH*0.3, 0);
    panelChooseHero.setFillColor(sf::Color::Black);

    panelSkills.setSize(sf::Vector2f(WIDTH*0.22, HEIGHT*0.30));
    panelSkills.setOutlineThickness(0);
    panelSkills.setOutlineColor(sf::Color::Blue);
    panelSkills.setPosition(WIDTH*0.74, HEIGHT*0.65);

    panelOptions.setSize(sf::Vector2f(WIDTH*0.4, HEIGHT*0.6));
    panelOptions.setOutlineThickness(-10);
    panelOptions.setOutlineColor(sf::Color::Magenta);
    panelOptions.setFillColor(sf::Color::Black);
    panelOptions.setPosition(WIDTH*0.3, HEIGHT*0.2);

    panelShop.setSize(sf::Vector2f(WIDTH*0.3, HEIGHT*0.5));
    panelShop.setOutlineThickness(-5);
    panelShop.setOutlineColor(sf::Color::Blue);
    panelShop.setPosition(WIDTH*0.7, HEIGHT*0.1);
    panelShop.setFillColor(sf::Color::Black);

}

void Resources::loadTexts()
{
    textGameOver.setString("GAME \nOVER");
    textGameOver.setFont(fontPixel);
    textGameOver.setCharacterSize(WIDTH*0.1);
    textGameOver.setPosition(WIDTH*0.385, HEIGHT*0.305);
    textGameOver.setFillColor(sf::Color::Magenta);

    textCurrentMoney.setFont(fontPixel);
    textCurrentMoney.setCharacterSize(WIDTH*0.02);
    textCurrentMoney.setPosition(WIDTH*0.71, HEIGHT*0.03);
    textCurrentMoney.setFillColor(sf::Color::Yellow);

    textChooseHero.setString("  Choose \nyour hero!");
    textChooseHero.setFont(fontPixel);
    textChooseHero.setCharacterSize(WIDTH*0.06);
    textChooseHero.setPosition(WIDTH*0.33, HEIGHT*0.04);
    textChooseHero.setFillColor(sf::Color::White);

    textSkillCooldown.setFont(fontPixel);
    textSkillCooldown.setCharacterSize(WIDTH*0.0275);
    textSkillCooldown.setPosition(WIDTH*0.71, HEIGHT*0.62);
    textSkillCooldown.setFillColor(sf::Color::Magenta);

    textOptions.setString("OPTIONS");
    textOptions.setFont(fontPixel);
    textOptions.setCharacterSize(WIDTH*0.05);
    textOptions.setPosition(WIDTH*0.4, HEIGHT*0.25);
    textOptions.setFillColor(sf::Color::White);
}

void Resources::loadSounds()
{
    bufferGameOver.loadFromFile("sounds/soundGameOver.wav");
    soundGameOver.setBuffer(bufferGameOver);

    bufferWeaponMelee.loadFromFile("sounds/soundWeaponMelee.wav");
    soundWeaponMelee.setBuffer(bufferWeaponMelee);

    bufferWeaponWand.loadFromFile("sounds/soundWeaponWand.wav");
    soundWeaponWand.setBuffer(bufferWeaponWand);

    bufferButtonClick.loadFromFile("sounds/soundButtonClick.wav");
    soundButtonClick.setBuffer(bufferButtonClick);

    bufferZombie.loadFromFile("sounds/soundZombie.wav");
    soundZombie.setBuffer(bufferZombie);

    bufferBat.loadFromFile("sounds/soundBat.wav");
    soundBat.setBuffer(bufferBat);

    bufferGhost.loadFromFile("sounds/soundGhost.wav");
    soundGhost.setBuffer(bufferGhost);

    bufferSpider.loadFromFile("sounds/soundSpider.wav");
    soundSpider.setBuffer(bufferSpider);

    bufferSkeleton.loadFromFile("sounds/soundSkeleton.wav");
    soundSkeleton.setBuffer(bufferSkeleton);

    bufferChest.loadFromFile("sounds/soundChest.wav");
    soundChest.setBuffer(bufferChest);

    bufferCoin.loadFromFile("sounds/soundCoin.wav");
    soundCoin.setBuffer(bufferCoin);
    soundRubin.setBuffer(bufferCoin);
    soundRubin.setPitch(0.4);

    bufferPotion.loadFromFile("sounds/soundPotion.wav");
    soundPotion.setBuffer(bufferPotion);

    bufferDoughnut.loadFromFile("sounds/soundDoughnut.wav");
    soundDoughnut.setBuffer(bufferDoughnut);

    bufferSkillKnight.loadFromFile("sounds/soundSkillKnight.wav");
    soundSkillKnight.setBuffer(bufferSkillKnight);

    bufferSkillMage.loadFromFile("sounds/soundSkillMage.wav");
    soundSkillMage.setBuffer(bufferSkillMage);

    bufferChange.loadFromFile("sounds/soundChange.wav");
    soundSkillRouge.setBuffer(bufferChange);

    musicGame.openFromFile("sounds/musicGame.wav");
}

void Resources::soundOff()
{
    soundGameOver.setVolume(0);
    soundWeaponMelee.setVolume(0);
    soundWeaponWand.setVolume(0);
    soundButtonClick.setVolume(0);
    soundZombie.setVolume(0);
    soundSkeleton.setVolume(0);
    soundGhost.setVolume(0);
    soundBat.setVolume(0);
    soundSpider.setVolume(0);
    soundChest.setVolume(0);
    soundPotion.setVolume(0);
    soundDoughnut.setVolume(0);
    soundCoin.setVolume(0);
    soundRubin.setVolume(0);
    soundSkillKnight.setVolume(0);
    soundSkillMage.setVolume(0);
    soundSkillRouge.setVolume(0);
}

void Resources::soundOn()
{
    soundGameOver.setVolume(100);
    soundWeaponMelee.setVolume(100);
    soundWeaponWand.setVolume(100);
    soundButtonClick.setVolume(100);
    soundZombie.setVolume(100);
    soundSkeleton.setVolume(100);
    soundGhost.setVolume(100);
    soundBat.setVolume(100);
    soundSpider.setVolume(100);
    soundChest.setVolume(100);
    soundPotion.setVolume(100);
    soundDoughnut.setVolume(100);
    soundCoin.setVolume(100);
    soundRubin.setVolume(100);
    soundSkillKnight.setVolume(100);
    soundSkillMage.setVolume(100);
    soundSkillRouge.setVolume(100);
}

bool Resources::ifAnimationsAreDone()
{
    for(int i = 0; i<9; i++)
    {
        if(animationTime[i] != 0) return false;
        if(animationRight[i] != 0) return false;
        if(animationLeft[i] != 0) return false;
        if(animationUp[i] != 0) return false;
        if(animationDown[i] != 0) return false;
    }

    return true;
}

