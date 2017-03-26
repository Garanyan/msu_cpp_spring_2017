#pragma once
#include "include.h"

class Armor;

class Weapon {
public:
    int radius;
    int speed;
    Weapon(int radius = 0, int speed = 0);
    Weapon(const Weapon & copied) = delete;
    Weapon & operator= (const Weapon & copied) = delete;
    Weapon(Weapon && moved);
    Weapon & operator= (Weapon && moved); 
    virtual int countbonus(Armor &a);
};

class Nothing : public Weapon
{
public:
    static constexpr const char * name = "Nothing";
    int countbonus(Armor &armor);
    Nothing(int nothingradius = 0, int nothingspeed = 30);
    Nothing(const Nothing & copied) = delete;
    Nothing & operator= (const Nothing & copied) = delete;
    Nothing(Nothing && moved);
    Nothing & operator= (Nothing && moved); 
};

class Sword : public Weapon
{
public:
    static constexpr const char * name = "Sword";
    Sword(int swordradius = 20, int swordspeed = 30);
    Sword(const Sword & copied) = delete;
    Sword & operator= (const Sword & copied) = delete;
    Sword(Sword && moved);
    Sword & operator= (Sword && moved); 
};

class Shovel : public Weapon
{
public:
    static constexpr const char * name = "Shovel";
    Shovel(int shovelradius = 20, int shovelspeed = 40);
    Shovel(const Shovel & copied) = delete;
    Shovel & operator= (const Shovel & copied) = delete;
    Shovel(Shovel && moved);
    Shovel & operator= (Shovel && moved); 
};

class Bow : public Weapon
{
public:
    static constexpr const char * name = "Bow";
    Bow(int bowradius = 50, int bowspeed = 10);
    Bow(const Bow & copied) = delete;
    Bow & operator= (const Bow & copied) = delete;
    Bow(Bow && moved);
    Bow & operator= (Bow && moved); 
};

class Hammer : public Weapon
{
public:
    static constexpr const char * name = "Hammer";
    Hammer(int hammerradius = 20, int hammerspeed = 10);
    Hammer(const Hammer & copied) = delete;
    Hammer & operator= (const Hammer & copied) = delete;
    Hammer(Hammer && moved);
    Hammer & operator= (Hammer && moved); 
};
