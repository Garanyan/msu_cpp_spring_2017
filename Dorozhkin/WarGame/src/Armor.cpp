#pragma once
#include "../include/Armor.h"
#include "../include/Weapon.h"

//Armor
Armor::Armor(int speedpenalty)
{
    this->speedpenalty = speedpenalty;
}
Armor::Armor(Armor && moved)
{
    this->speedpenalty = std::move(moved.speedpenalty);
}

Armor &Armor::operator=(Armor && moved)
{
    this->speedpenalty = std::move(moved.speedpenalty);
    return *this;
}

int Armor::countbonus(Weapon &weapon) 
{
    return this->speedpenalty - weapon.radius - weapon.speed; 
}

//Torso
//default values for Torso
Torso::Torso(int torsospeedpenalty) : 
    Armor(torsospeedpenalty)
{
}

Torso::Torso(Torso && moved)
{
    this->speedpenalty = std::move(moved.speedpenalty);
}

Torso &Torso::operator=(Torso && moved)
{
    this->speedpenalty = std::move(moved.speedpenalty);
    return *this;
}

//Chain
//default values for Chain
Chain::Chain(int chainspeedpenalty) :
    Armor(chainspeedpenalty)
{
}

Chain::Chain(Chain && moved)
{
    this->speedpenalty = std::move(moved.speedpenalty);
}

Chain &Chain::operator=(Chain && moved)
{
    this->speedpenalty = std::move(moved.speedpenalty);
    return *this;
}

//Corslet
//default values for Corslet
Corslet::Corslet(int corsletspeedpenalty) :
    Armor(corsletspeedpenalty)
{
}

Corslet::Corslet(Corslet && moved)
{
    this->speedpenalty = std::move(moved.speedpenalty);
}

Corslet &Corslet::operator=(Corslet && moved)
{
    this->speedpenalty = std::move(moved.speedpenalty);
    return *this;
}
