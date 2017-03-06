#pragma once

#include "Armor.h"
#include "Weapon.h"

class Human {
    int forse;
    int speed;
    int skill;
    int endurance;
    Weapon weapon;
    Armor armor;
    void takeweapon(Weapon &w);
    void takearmor(Armor &a);
    int takedamage(Human &h);
    int dealdamage(Human &h);
};

class Peasent : public Human {
    
};

class Archer : public Human {
    
};

class Knight : public Human {
    
};
