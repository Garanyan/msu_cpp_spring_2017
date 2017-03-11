#ifndef PEASANT_CHARACTER_H
#define PEASANT_CHARACTER_H

#include "Character.h"

class PeasantCharacter : public Character
{
public:
    unsigned strength;
    unsigned endurance;
    unsigned speed;
    unsigned weaponSkill;
};

#endif