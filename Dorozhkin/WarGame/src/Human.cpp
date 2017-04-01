#pragma once
#include "../include/Human.h"
#include "../include/Weapon.h"
#include "../include/Armor.h"


//Human
Human::~Human()
{
    
}

Human::Human(int forse, int speed, int skill, int endurance, int life)
{
    this->forse = forse;
    this->skill = skill;
    this->endurance = endurance;
    this->speed = speed;
    this->life = life;
    this->name = generatename();
    this->weapon.reset(new Nothing());
    this->armor.reset(new Torso());
} 

// Human::Human(Human && moved)
// {
//     this->name = std::move(moved.name);
//     this->forse = std::move(moved.forse);
//     this->skill = std::move(moved.skill);
//     this->endurance = std::move(moved.endurance);
//     this->speed = std::move(moved.speed);
//     this->weapon = std::move(moved.weapon);
//     this->armor = std::move(moved.armor);
//     this->life = std::move(moved.life);
// }

// Human &Human::operator=(Human && moved)
// {
//     this->name = std::move(moved.name);
//     this->forse = std::move(moved.forse);
//     this->skill = std::move(moved.skill);
//     this->endurance = std::move(moved.endurance);
//     this->speed = std::move(moved.speed);
//     this->weapon = std::move(moved.weapon);
//     this->armor = std::move(moved.armor);
//     this->life = std::move(moved.life);
//     return *this;
// }

// Human& Human::takeweapon(Weapon &weapon)
// {
//     this->weapon = std::move(weapon);
//     return *this;
// }
// 
// Human& Human::takearmor(Armor &armor)
// {
//     this->armor = std::move(armor);
//     return *this;
// }

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
    return "Denis" + std::to_string(rand());
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
Peasant::Peasant(int peasantforse, int peasantspeed, int peasantskill, int peasantendurance, int peasantlife) :
    Human(peasantforse, peasantspeed, peasantskill, peasantendurance, peasantlife)
{
}

HumanProfession Peasant::getprofession() const 
{
    return HumanProfession::Peasant;
}

// Peasant::Peasant(Peasant && moved)
// {
//     this->name = std::move(moved.name);
//     this->forse = std::move(moved.forse);
//     this->skill = std::move(moved.skill);
//     this->endurance = std::move(moved.endurance);
//     this->speed = std::move(moved.speed);
//     this->weapon = std::move(moved.weapon);
//     this->armor = std::move(moved.armor);
//     this->life = std::move(moved.life);
// }
// 
// Peasant &Peasant::operator=(Peasant && moved)
// {
//     this->name = std::move(moved.name);
//     this->forse = std::move(moved.forse);
//     this->skill = std::move(moved.skill);
//     this->endurance = std::move(moved.endurance);
//     this->speed = std::move(moved.speed);
//     this->weapon = std::move(moved.weapon);
//     this->armor = std::move(moved.armor);
//     this->life = std::move(moved.life);
//     return *this;
// }

//Archer
// default values for Archer
Archer::Archer(int archerforse, int archerspeed, int archerskill, int archerendurance, int archerlife) :
    Human(archerforse, archerspeed, archerskill, archerendurance, archerlife)
{    
}

HumanProfession Archer::getprofession() const 
{
    return HumanProfession::Archer;
}

// Archer::Archer(Archer && moved)
// {
//     this->name = std::move(moved.name);
//     this->forse = std::move(moved.forse);
//     this->skill = std::move(moved.skill);
//     this->endurance = std::move(moved.endurance);
//     this->speed = std::move(moved.speed);
//     this->weapon = std::move(moved.weapon);
//     this->armor = std::move(moved.armor);
//     this->life = std::move(moved.life);
// }
// 
// Archer &Archer::operator=(Archer && moved)
// {
//     this->name = std::move(moved.name);
//     this->forse = std::move(moved.forse);
//     this->skill = std::move(moved.skill);
//     this->endurance = std::move(moved.endurance);
//     this->speed = std::move(moved.speed);
//     this->weapon = std::move(moved.weapon);
//     this->armor = std::move(moved.armor);
//     this->life = std::move(moved.life);
//     return *this;
// }

//Knight
// default values for Knight
Knight::Knight(int knightforse, int knightspeed, int knightskill, int knightendurance, int knightlife) :
    Human(knightforse, knightspeed, knightskill, knightendurance, knightlife)
{    
}

HumanProfession Knight::getprofession() const 
{
    return HumanProfession::Knight;
}

// Knight::Knight(Knight && moved)
// {
//     this->name = std::move(moved.name);
//     this->forse = std::move(moved.forse);
//     this->skill = std::move(moved.skill);
//     this->endurance = std::move(moved.endurance);
//     this->speed = std::move(moved.speed);
//     this->weapon = std::move(moved.weapon);
//     this->armor = std::move(moved.armor);
//     this->life = std::move(moved.life);
// }
// 
// Knight &Knight::operator=(Knight && moved)
// {
//     this->name = std::move(moved.name);
//     this->forse = std::move(moved.forse);
//     this->skill = std::move(moved.skill);
//     this->endurance = std::move(moved.endurance);
//     this->speed = std::move(moved.speed);
//     this->weapon = std::move(moved.weapon);
//     this->armor = std::move(moved.armor);
//     this->life = std::move(moved.life);
//     return *this;
// }
