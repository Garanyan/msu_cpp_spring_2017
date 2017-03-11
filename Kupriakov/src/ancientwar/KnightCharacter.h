#ifndef KNIGHT_CHARACTER_H
#define KNIGHT_CHARACTER_H

#include "Character.h"

class KnightCharacter : public Character
{
public:
    unsigned strength;
    unsigned endurance;
    unsigned speed;
    unsigned weaponSkill;
};

#endif