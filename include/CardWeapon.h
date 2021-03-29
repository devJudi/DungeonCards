#ifndef CARDWEAPON_H
#define CARDWEAPON_H

#include "CardMonster.h"

extern sf::Texture texCardWeaponSword;
extern sf::Texture texCardWeaponWandIce;
extern sf::Texture texCardWeaponPoisonedDagger;
extern sf::Texture texInfoSword;
extern sf::Texture texInfoWandIce;
extern sf::Texture texInfoPoisonedDagger;

class CardWeapon : public Card
{
    public:
        CardWeapon();
        CardWeapon(Weapons weapon);
        CardWeapon(const CardWeapon &copiedCard);
        void drawHp(sf::RenderWindow &window);
        bool mouseClicked(sf::Vector2i mousePos, Card* cards[9], CardHero* hero);
        CardTypes getCardType();
        virtual ~CardWeapon();
        void setDamage();

        int damage;
        Weapons weaponType;

    protected:

    private:
};

#endif // CARDWEAPON_H
