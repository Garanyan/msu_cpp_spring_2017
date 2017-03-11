#pragma once
#include "armor.h"

class Weapon{
    const double penetrationCorslet;
    const double penetrationChains;
    const double velocity;
    const double range;
public:
    const double count_penetration(const Armor& armor);
};

class Shovel : public Weapon{

};

class Bow : public Weapon{

};

class Hammer : public Weapon{

};

class Sword : public Weapon{

};
