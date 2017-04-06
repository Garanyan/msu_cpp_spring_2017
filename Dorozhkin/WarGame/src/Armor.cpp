#pragma once
#include "../include/Armor.h"
#include "../include/Weapon.h"

//Armor
Armor::~Armor()
{
    
}

Armor::Armor(int speedpenalty)
{
    this->speedpenalty = speedpenalty;
}

int Armor::countbonus(std::unique_ptr<Weapon>& weapon) 
{
    return this->speedpenalty - weapon->radius - weapon->speed; 
}

//Torso
//default values for Torso
Torso::Torso(int torsospeedpenalty) : 
    Armor(torsospeedpenalty)
{
}

ArmorName Torso::getname() const 
{
    return ArmorName::Torso;
}

//Chain
//default values for Chain
Chain::Chain(int chainspeedpenalty) :
    Armor(chainspeedpenalty)
{
}

ArmorName Chain::getname() const
{
    return ArmorName::Chain;
}

//Corslet
//default values for Corslet
Corslet::Corslet(int corsletspeedpenalty) :
    Armor(corsletspeedpenalty)
{
}

ArmorName Corslet::getname() const
{
    return ArmorName::Corslet;
}
