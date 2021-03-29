#ifndef CARDHERO_H
#define CARDHERO_H

#include "Card.h"

extern sf::Texture texCardHeroKnight;
extern sf::Texture texCardHeroMage;
extern sf::Texture texCardHeroRouge;

extern sf::Texture texInfoKnight;
extern sf::Texture texInfoMage;
extern sf::Texture texInfoRouge;

extern sf::Font fontPixel;

extern sf::Sound soundGameOver;
extern sf::Sound soundWeaponMelee;
extern sf::Sound soundWeaponWand;

extern bool isGameOver;
extern int animationSword[9];

extern long long int earnedCoins;

enum Weapons
{
    none = -1,
    sword = 0,
    wandIce,
    poisonedDagger
};

enum Heroes
{
    knight = 0,
    mage,
    rouge
};

class CardHero : public Card
{
    public:
        CardHero(Heroes hero = knight);
        CardHero(const CardHero &copiedCard);
        void doAction();
        bool mouseClicked(sf::Vector2i mousePos, Card* cards[9], CardHero* hero);
        void drawHp(sf::RenderWindow &window);
        CardTypes getCardType();
        void setCardGraphics();
        void giveWeapon(Weapons weapon, int damage);
        int doAttack(int opponentHp);
        void useSkill(Card* cards[9]);
        bool increasceHp();
        bool decreasceSkillCooldown();
        bool improveSkill();
        virtual ~CardHero();

        Heroes heroType;
        Weapons heroWeapon;
        Weapons lastWeaponUsed;
        int hp;
        int maxHp;
        int attack;
        int skillCooldown;
        int currentCooldown;
        int skillImprovements;
        bool isWeaponUsed;

    protected:

    private:
};

#endif // CARDHERO_H
