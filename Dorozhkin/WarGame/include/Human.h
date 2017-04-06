#pragma once
#include "Armor.h"
#include "Weapon.h"
#include "include.h"

enum class HumanProfession { Peasant, Archer, Knight }; 

class Human
{
public:
    std::string name;
    int forse;
    int speed;
    int skill;
    int endurance;
    int life;
    std::unique_ptr<Weapon> weapon;
    std::unique_ptr<Armor> armor;
    std::string generatename();
    int takedamage(std::unique_ptr<Human>& human);
    int dealdamage(std::unique_ptr<Human>& human);
    int getoffensepower();
    int getdefensepower();
    Human(std::string name = "default", int forse = 0, int speed = 0, int skill = 0, int endurance = 0, int life = 100); 
    Human(const Human & copied) = delete;
    Human & operator= (const Human & copied) = delete;
    virtual ~Human();  
    virtual HumanProfession getprofession() const = 0;
};

class Peasant : public Human
{
public:
    Peasant(std::string name = "default", int peasantforse = 50, int peasantspeed = 20, int peasantskill = 10, int peasantendurance = 20, int peasantlife = 100); 
    Peasant(const Peasant & copied) = delete;
    Peasant & operator= (const Peasant & copied) = delete;
    HumanProfession getprofession() const;
};

class Archer : public Human
{
public:
    Archer(std::string name = "default", int archerforse = 30, int archerspeed = 40, int archerskill = 30, int archerendurance = 20, int archerlife = 100); 
    Archer(const Archer & copied) = delete;
    Archer & operator= (const Archer & copied) = delete;
    HumanProfession getprofession() const;
};

class Knight : public Human
{
public:
    Knight(std::string name = "default", int knightforse = 70, int knightspeed = 10, int knightskill = 40, int knightendurance = 50, int knightlife = 140); 
    Knight(const Knight & copied) = delete;
    Knight & operator= (const Knight & copied) = delete;
    HumanProfession getprofession() const;
};
