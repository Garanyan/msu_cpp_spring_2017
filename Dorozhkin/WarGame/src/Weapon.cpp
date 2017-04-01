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

// Weapon::Weapon(Weapon && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
// }
// 
// Weapon &Weapon::operator=(Weapon && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
//     return *this;
// }

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

// Nothing::Nothing(Nothing && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
// }
// 
// Nothing &Nothing::operator=(Nothing && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
//     return *this;
// }

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

// Sword::Sword(Sword && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
// }
// 
// Sword &Sword::operator=(Sword && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
//     return *this;
// }

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

// Shovel::Shovel(Shovel && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
// }
// 
// Shovel &Shovel::operator=(Shovel && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
//     return *this;
// }

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

// Bow::Bow(Bow && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
// }
// 
// Bow &Bow::operator=(Bow && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
//     return *this;
// }

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

// Hammer::Hammer(Hammer && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
// }
// 
// Hammer &Hammer::operator=(Hammer && moved)
// {
//     this->radius = std::move(moved.radius);
//     this->speed = std::move(moved.speed);
//     return *this;
// }
