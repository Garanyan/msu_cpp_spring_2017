#ifndef SWORD_WEAPON_H
#define SWORD_WEAPON_H

#include "Character.h"
class SwordWeapon : public Character
{
public:
    unsigned rate;
    unsigned distance;
    unsigned damage;
private:
    unsigned damageMultiplier(unsigned damage);
};

#endif