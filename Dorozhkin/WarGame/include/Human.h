#pragma once
#include "Armor.h"
#include "Weapon.h"
#include "include.h"

class Human
{
public:
    std::string name;
    int forse;
    int speed;
    int skill;
    int endurance;
    int life;
    Weapon weapon;
    Armor armor;
    std::string generatename();
    int takedamage(Human &human);
    int dealdamage(Human &human);
    int getoffensepower();
    int getdefensepower();
    Human& takeweapon(Weapon &weapon);
    Human& takearmor(Armor &armor);
    Human(int forse = 0, int speed = 0, int skill = 0, int endurance = 0, int life = 100); 
    Human(const Human & copied) = delete;
    Human & operator= (const Human & copied) = delete;
    Human(Human && moved);
    Human & operator= (Human && moved);   
};

class Peasant : public Human
{
public:
    Peasant(int peasantforse = 50, int peasantspeed = 20, int peasantskill = 10, int peasantendurance = 20, int peasantlife = 100); 
    Peasant(const Peasant & copied) = delete;
    Peasant & operator= (const Peasant & copied) = delete;
    Peasant(Peasant && moved);
    Peasant & operator= (Peasant && moved); 
};

class Archer : public Human
{
public:
    Archer(int archerforse = 30, int archerspeed = 40, int archerskill = 30, int archerendurance = 20, int archerlife = 100); 
    Archer(const Archer & copied) = delete;
    Archer & operator= (const Archer & copied) = delete;
    Archer(Archer && moved);
    Archer & operator= (Archer && moved); 
};

class Knight : public Human
{
public:
    Knight(int knightforse = 70, int knightspeed = 10, int knightskill = 40, int knightendurance = 50, int knightlife = 140); 
    Knight(const Knight & copied) = delete;
    Knight & operator= (const Knight & copied) = delete;
    Knight(Knight && moved);
    Knight & operator= (Knight && moved); 
};
