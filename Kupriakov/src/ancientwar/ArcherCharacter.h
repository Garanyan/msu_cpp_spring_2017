#ifndef ARCHER_CHARACTER_H
#define ARCHER_CHARACTER_H

#include "Character.h"

class ArcherCharacter : public Character
{
public:
    unsigned strength;
    unsigned endurance;
    unsigned speed;
    unsigned weaponSkill;
};

#endif