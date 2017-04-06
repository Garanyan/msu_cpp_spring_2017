#pragma once
#include "../include/Human.h"
#include "../include/Weapon.h"
#include "../include/Armor.h"


//Human
Human::~Human()
{
    
}

Human::Human(std::string name, int forse, int speed, int skill, int endurance, int life)
{
    this->forse = forse;
    this->skill = skill;
    this->endurance = endurance;
    this->speed = speed;
    this->life = life;
    this->name = name == "default" ? generatename() : name;
    this->weapon.reset(new Nothing());
    this->armor.reset(new Torso());
} 

int Human::takedamage(std::unique_ptr<Human>& enemy)
{
    return enemy->getoffensepower() - this->getdefensepower() + this->armor->countbonus(enemy->weapon) - enemy->weapon->countbonus(this->armor);
}

int Human::dealdamage(std::unique_ptr<Human>& enemy)
{
    return this->getoffensepower() - enemy->getdefensepower() + this->weapon->countbonus(enemy->armor) - enemy->armor->countbonus(this->weapon);
}

std::string Human::generatename()
{
    return std::to_string(rand() + rand());
}

int Human::getoffensepower()
{
     return forse + skill + this->weapon->radius + this->weapon->speed;
}

int Human::getdefensepower()
{
     return endurance + speed - this->armor->speedpenalty;
}

//Peasant
//default values for Peasant
Peasant::Peasant(std::string name, int peasantforse, int peasantspeed, int peasantskill, int peasantendurance, int peasantlife) :
    Human(name, peasantforse, peasantspeed, peasantskill, peasantendurance, peasantlife)
{
}

HumanProfession Peasant::getprofession() const 
{
    return HumanProfession::Peasant;
}

//Archer
// default values for Archer
Archer::Archer(std::string name, int archerforse, int archerspeed, int archerskill, int archerendurance, int archerlife) :
    Human(name, archerforse, archerspeed, archerskill, archerendurance, archerlife)
{    
}

HumanProfession Archer::getprofession() const 
{
    return HumanProfession::Archer;
}

//Knight
// default values for Knight
Knight::Knight(std::string name, int knightforse, int knightspeed, int knightskill, int knightendurance, int knightlife) :
    Human(name, knightforse, knightspeed, knightskill, knightendurance, knightlife)
{    
}

HumanProfession Knight::getprofession() const 
{
    return HumanProfession::Knight;
}
