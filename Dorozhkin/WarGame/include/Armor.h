#pragma once
#include "include.h"

class Weapon;

class Armor 
{
public:
    int speedpenalty;
    int countbonus(Weapon &weapon);
    Armor(int speedpenalty = 0);
    Armor(const Armor & copied) = delete;
    Armor & operator= (const Armor & copied) = delete;
    Armor(Armor && moved);
    Armor & operator= (Armor && moved); 
};

class Torso : public Armor
{
public:
    static constexpr const char * name = "Torso";
    Torso(int torsospeedpenalty = 0);
    Torso(const Torso & copied) = delete;
    Torso & operator= (const Torso & copied) = delete;
    Torso(Torso && moved);
    Torso & operator= (Torso && moved); 
};

class Chain : public Armor
{
public:
    static constexpr const char * name = "Chain";
    Chain(int chainspeedpenalty = 20);
    Chain(const Chain & copied) = delete;
    Chain & operator= (const Chain & copied) = delete;
    Chain(Chain && moved);
    Chain & operator= (Chain && moved); 
};

class Corslet : public Armor
{
public:
    static constexpr const char * name = "Corslet";
    Corslet(int corsletspeedpenalty = 30);
    Corslet(const Corslet & copied) = delete;
    Corslet & operator= (const Corslet & copied) = delete;
    Corslet(Corslet && moved);
    Corslet & operator= (Corslet && moved); 
};
