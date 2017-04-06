#pragma once
#include "include.h"

class Weapon;

enum class ArmorName { Torso, Chain, Corslet, Armor };

class Armor 
{
public:
    int speedpenalty;
    int countbonus(std::unique_ptr<Weapon>& weapon);
    Armor(int speedpenalty = 0);
    Armor(const Armor & copied) = delete;
    Armor & operator= (const Armor & copied) = delete;
    virtual ~Armor();
    virtual ArmorName getname() const = 0;
    static constexpr ArmorName name = ArmorName::Armor;
};

class Torso : public Armor
{
public:
    Torso(int torsospeedpenalty = 0);
    Torso(const Torso & copied) = delete;
    Torso & operator= (const Torso & copied) = delete;
    ArmorName getname() const;
    static constexpr ArmorName name = ArmorName::Torso;
};

class Chain : public Armor
{
public:
    Chain(int chainspeedpenalty = 20);
    Chain(const Chain & copied) = delete;
    Chain & operator= (const Chain & copied) = delete;
    ArmorName getname() const;
    static constexpr ArmorName name = ArmorName::Chain;
};

class Corslet : public Armor
{
public:
    Corslet(int corsletspeedpenalty = 30);
    Corslet(const Corslet & copied) = delete;
    Corslet & operator= (const Corslet & copied) = delete;
    ArmorName getname() const;
    static constexpr ArmorName name = ArmorName::Corslet;
};
