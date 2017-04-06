#pragma once
#include "include.h"

class Armor;

enum class WeaponName { Sword, Hammer, Bow, Nothing, Shovel, Weapon };

class Weapon {
public:
    int radius;
    int speed;
    Weapon(int radius = 0, int speed = 0);
    Weapon(const Weapon & copied) = delete;
    Weapon & operator= (const Weapon & copied) = delete;
    virtual int countbonus(std::unique_ptr<Armor>& armor);
    virtual ~Weapon();
    virtual WeaponName getname() const = 0;
    static constexpr WeaponName name = WeaponName::Weapon;
};

class Nothing : public Weapon
{
public:
    int countbonus(Armor &armor);
    Nothing(int nothingradius = 0, int nothingspeed = 30);
    Nothing(const Nothing & copied) = delete;
    Nothing & operator= (const Nothing & copied) = delete;
    WeaponName getname() const;
    static constexpr WeaponName name = WeaponName::Nothing;
};

class Sword : public Weapon
{
public:
    Sword(int swordradius = 20, int swordspeed = 30);
    Sword(const Sword & copied) = delete;
    Sword & operator= (const Sword & copied) = delete;
    WeaponName getname() const;
    static constexpr WeaponName name = WeaponName::Sword;
};

class Shovel : public Weapon
{
public:
    Shovel(int shovelradius = 20, int shovelspeed = 40);
    Shovel(const Shovel & copied) = delete;
    Shovel & operator= (const Shovel & copied) = delete;
    WeaponName getname() const;
    static constexpr WeaponName name = WeaponName::Shovel;
};

class Bow : public Weapon
{
public:
    Bow(int bowradius = 50, int bowspeed = 10);
    Bow(const Bow & copied) = delete;
    Bow & operator= (const Bow & copied) = delete;
    WeaponName getname() const;
    static constexpr WeaponName name = WeaponName::Bow;
};

class Hammer : public Weapon
{
public:
    Hammer(int hammerradius = 20, int hammerspeed = 10);
    Hammer(const Hammer & copied) = delete;
    Hammer & operator= (const Hammer & copied) = delete;
    WeaponName getname() const;
    static constexpr WeaponName name = WeaponName::Hammer;
};
