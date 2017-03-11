#pragma once

#include "Armor.h"
#include "Weapon.h"
#include "include.h"

class Human
{
    std::string name;
    std::string coordinate;
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
    std::string generatenewname();
public:
    Human(const Human & copied) = delete;
    Human & operator= (const Human & copied) = delete;
    Human(Human && moved);
    Human & operator= (Human && moved);    
};

class Peasant : public Human
{
public:
    Peasant(int forse, int speed, int skill, int endurance); 
    Peasant(const Peasant & copied) = delete;
    Peasant & operator= (const Peasant & copied) = delete;
    Peasant(Peasant && moved);
    Peasant & operator= (Peasant && moved); 
};

class Archer : public Human
{
public:
    Archer(int forse, int speed, int skill, int endurance); 
    Archer(const Archer & copied) = delete;
    Archer & operator= (const Archer & copied) = delete;
    Archer(Archer && moved);
    Archer & operator= (Archer && moved); 
};

class Knight : public Human
{
public:
    Knight(int forse, int speed, int skill, int endurance); 
    Knight(const Knight & copied) = delete;
    Knight & operator= (const Knight & copied) = delete;
    Knight(Knight && moved);
    Knight & operator= (Knight && moved); 
};
