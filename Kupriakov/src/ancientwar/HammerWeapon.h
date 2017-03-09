#ifndef HAMMER_WEAPON_H
#define HAMMER_WEAPON_H

#include "Character.h"
class HammerWeapon : public Character
{
public:
    unsigned rate;
    unsigned distance;
    unsigned damage;
private:
    unsigned damageMultiplier(unsigned damage);
};

#endif