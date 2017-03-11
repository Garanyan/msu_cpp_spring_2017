#ifndef BOW_WEAPON_H
#define BOW_WEAPON_H

#include "Character.h"
class BowWeapon : public Character
{
public:
    unsigned arrows;
private:
    unsigned damageMultiplier(unsigned damage);
};

#endif