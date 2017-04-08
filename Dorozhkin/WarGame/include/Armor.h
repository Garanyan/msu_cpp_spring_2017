#pragma once
#include "include.h"
// precompiled headers - по другому работает

class Weapon;

enum class ArmorName { Torso, Chain, Corslet, Armor };

// инкапсуляция, БОЛЬШЕ КОНСТАНТ
// camel case QT style
class Armor 
{
    // int speedpenalty;
    const int speedPenalty_;
public:
//    using healthPoints = int;
    // int countBonus(const std::unique_ptr<Weapon>& weapon) const; //const&, const method
    int countBonus(const Weapon& weapon) const; //const&
    // healthPoints countbonus(const Weapon& weapon) const; //const&
    Armor(int speedPenalty = 0);
    Armor(const Armor& copied) = delete;
    Armor& operator= (const Armor& copied) = delete;
    virtual ~Armor();
    virtual ArmorName getName() const = 0;
    static constexpr ArmorName name = ArmorName::Armor;
    int getPower() const; 
};

class Torso : public Armor
{
public:
    Torso(int torsoSpeedPenalty = 0);
    Torso(const Torso& copied) = delete;
    Torso& operator= (const Torso& copied) = delete;
    ArmorName getName() const override; // override
    static constexpr ArmorName name = ArmorName::Torso;
};

class Chain : public Armor
{
public:
    Chain(int chainSpeedPenalty = 20);
    Chain(const Chain& copied) = delete;
    Chain& operator= (const Chain& copied) = delete;
    ArmorName getName() const override;
    static constexpr ArmorName name = ArmorName::Chain;
};

class Corslet : public Armor
{
public:
    Corslet(int corsletSpeedPenalty = 30);
    Corslet(const Corslet& copied) = delete;
    Corslet& operator= (const Corslet& copied) = delete;
    ArmorName getName() const override;
    static constexpr ArmorName name = ArmorName::Corslet;
};
