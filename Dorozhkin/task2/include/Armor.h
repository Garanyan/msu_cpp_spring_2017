#pragma once
#include "include.h"

class Weapon;

class Armor 
{
    int speedpenalty;
public:
    virtual int countbonus(Weapon &w);
    Armor(const Armor & copied) = delete;
    Armor & operator= (const Armor & copied) = delete;
    Armor(Armor && moved);
    Armor & operator= (Armor && moved); 
};

class Torso : public Armor
{
public:
    int countbonus(Weapon &w);
    Torso(int speedpenalty);
    Torso(const Torso & copied) = delete;
    Torso & operator= (const Torso & copied) = delete;
    Torso(Torso && moved);
    Torso & operator= (Torso && moved); 
};

class Chain : public Armor
{
public:
    int countbonus(Weapon &w);    
    Chain(int speedpenalty);
    Chain(const Chain & copied) = delete;
    Chain & operator= (const Chain & copied) = delete;
    Chain(Chain && moved);
    Chain & operator= (Chain && moved); 
};

class Corslet : public Armor
{
public:
    int countbonus(Weapon &w);
    Corslet(int speedpenalty);
    Corslet(const Corslet & copied) = delete;
    Corslet & operator= (const Corslet & copied) = delete;
    Corslet(Corslet && moved);
    Corslet & operator= (Corslet && moved); 
};
