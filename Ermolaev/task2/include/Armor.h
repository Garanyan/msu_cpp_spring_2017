#pragma once

#include "stdafx.h"
#include "utils.h"

// Armor
class Armor
{
public:
    Armor(Points durability, Points breakingSpeed, Points damageToWeapon);
    virtual ~Armor() = 0;

    Armor(const Armor& copied) = delete;
    Armor& operator= (const Armor& copied) = delete;

    virtual Points transferDamage(DamageType damage) const = 0;
    virtual std::string getName() const = 0;
    void printStats() const;
    Points takeAndTransferDamage(Points damage, DamageType type);
    Points getDurability() const;
    Points getDamageToWeapon() const;
private:
    Points durability_;
    Points breakingSpeed_;
    Points damageToWeapon_;
};


// WithoutArmor
class WithoutArmor
        : public Armor
{
public:
    WithoutArmor(Points durability=-1, Points breakingSpeed=1, Points damageToWeapon=0);
    Points transferDamage(DamageType damage) const override;
    std::string getName() const override;
};

// Chains
class Chains
        : public Armor
{
public:
    Chains(Points durability=60, Points breakingSpeed=0.2, Points damageToWeapon=1);
    Points transferDamage(DamageType damage) const override;
    std::string getName() const override;
};

// Plates
class Plates
        : public Armor
{
public:
    Plates(Points durability=100, Points breakingSpeed=0.4, Points damageToWeapon=3);
    Points transferDamage(DamageType damage) const override;
    std::string getName() const override;
};
