#pragma once
#include "armor.h"
#include "weapon.h"

class Character{
    double strength;
    double endurance;
    double velocity;
    const double skillsShovel;
    const double skillsBow;
    const double skillsHammer;
    const double skillsSword;
    Weapon weapon;
    Armor armor;
public:
    void PutOnArmor(Armor&& armor);
    void PutOnWeapon(Weapon&& weapon);
    Character(const Character& copied) = delete;
    Character& operator=(const Character& copied) = delete;
};

class Peasant : public Character{

};

class Knight : public Character{

};

class Archer : public Character{

};
