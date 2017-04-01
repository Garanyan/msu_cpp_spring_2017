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

// Armor::Armor(Armor && moved)
// {
//     this->speedpenalty = std::move(moved.speedpenalty);
// }
// 
// Armor &Armor::operator=(Armor && moved)
// {
//     this->speedpenalty = std::move(moved.speedpenalty);
//     return *this;
// }

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

// Torso::Torso(Torso && moved)
// {
//     this->speedpenalty = std::move(moved.speedpenalty);
// }
// 
// Torso &Torso::operator=(Torso && moved)
// {
//     this->speedpenalty = std::move(moved.speedpenalty);
//     return *this;
// }

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

// Chain::Chain(Chain && moved)
// {
//     this->speedpenalty = std::move(moved.speedpenalty);
// }
// 
// Chain &Chain::operator=(Chain && moved)
// {
//     this->speedpenalty = std::move(moved.speedpenalty);
//     return *this;
// }

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

// Corslet::Corslet(Corslet && moved)
// {
//     this->speedpenalty = std::move(moved.speedpenalty);
// }
// 
// Corslet &Corslet::operator=(Corslet && moved)
// {
//     this->speedpenalty = std::move(moved.speedpenalty);
//     return *this;
// }
