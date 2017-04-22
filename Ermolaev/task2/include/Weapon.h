#pragma once

#include "utils.h"
#include "stdafx.h"

// Weapon
class Weapon
{
public:
    explicit Weapon(Points durability, Points damage, Points breakingSpeed);
    virtual ~Weapon() = 0;

    Weapon(const Weapon& copied) = delete;
    Weapon& operator= (const Weapon& copied) = delete;

    virtual std::string getName() const = 0;
    void printStats() const;
    Points takeAndReturnDamage(Points armorResistance);
    virtual DamageType damageType() const = 0;
    Points getDurability() const;
private:
    Points durability_;
    Points breakingSpeed_;
    Points damage_;
};

// Fists
class Fists
        :public Weapon
{
public:
    Fists(Points durability = -1, Points damage = 5, Points breakingSpeed = 0);
    DamageType damageType() const override;
    std::string getName() const override;
};

// Sword
class Sword
        :public Weapon
{
public:
    Sword(Points durability = 1, Points damage = 40, Points breakingSpeed = 0.08);
    DamageType damageType() const override;
    std::string getName() const override;
};

// Bow
class Bow
        :public Weapon
{
public:
    Bow(Points durability = 1, Points damage = 20, Points breakingSpeed = 0.01);
    DamageType damageType() const override;
    std::string getName() const override;
};

