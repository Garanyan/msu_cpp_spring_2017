#pragma once
#include "weapon.h"

class Armor{
    const double protection;
    const double velocityPenalty;
public:
    const double countProtection(const Weapon& weapon);
    const double subtractVelocity();
};

class Corslet : public Armor{

}

class Chain : public Armor{

}
