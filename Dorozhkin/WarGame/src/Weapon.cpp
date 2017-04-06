#pragma once 
#include "../include/Weapon.h"
#include "../include/Armor.h"

//Weapon
Weapon::~Weapon()
{
    
}

Weapon::Weapon(int radius, int speed)
{
    this->radius = radius;
    this->speed = speed;
}

int Weapon::countbonus(std::unique_ptr<Armor>& armor) 
{
    return this->radius + this->speed - armor->speedpenalty; 
}

//Nothing
//default values for Nothing
Nothing::Nothing(int nothingradius, int nothingspeed) :
    Weapon(nothingradius, nothingspeed)
{
}

WeaponName Nothing::getname() const 
{
    return WeaponName::Nothing;
}

//Sword
//default values for Sword
Sword::Sword(int swordradius, int swordspeed) :
    Weapon(swordradius, swordspeed)
{
}

WeaponName Sword::getname() const 
{
    return WeaponName::Sword;
}

//Shovel
//default values for Shovel
Shovel::Shovel(int shovelradius, int shovelspeed) :
    Weapon(shovelradius, shovelspeed)
{
}

WeaponName Shovel::getname() const
{
    return WeaponName::Shovel;
}

//Bow
//default values for Bow
Bow::Bow(int bowradius, int bowspeed) :
    Weapon(bowradius, bowspeed)
{
}

WeaponName Bow::getname() const 
{
    return WeaponName::Bow;
}

//Hammer
//default values for Hammer
Hammer::Hammer(int hammerradius, int hammerspeed) :
    Weapon(hammerradius, hammerspeed)
{
}

WeaponName Hammer::getname() const 
{
    return WeaponName::Hammer;
}
