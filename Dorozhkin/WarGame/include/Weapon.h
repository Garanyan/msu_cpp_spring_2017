#pragma once
#include "include.h"

class Armor;

class Weapon {
    int radius;
    int speed;
public:
    virtual int countbonus(Armor &a);
};

class Nothing : public Weapon
{
public:
    int countbonus(Armor &a);
    Nothing(int radius, int speed);
    Nothing(const Nothing & copied) = delete;
    Nothing & operator= (const Nothing & copied) = delete;
    Nothing(Nothing && moved);
    Nothing & operator= (Nothing && moved); 
};

class Sword : public Weapon
{
public:
    int countbonus(Armor &a);
    Sword(int radius, int speed);
    Sword(const Sword & copied) = delete;
    Sword & operator= (const Sword & copied) = delete;
    Sword(Sword && moved);
    Sword & operator= (Sword && moved); 
};

class Shovel : public Weapon
{
public:
    int countbonus(Armor &a);
    Shovel(int radius, int speed);
    Shovel(const Shovel & copied) = delete;
    Shovel & operator= (const Shovel & copied) = delete;
    Shovel(Shovel && moved);
    Shovel & operator= (Shovel && moved); 
};

class Bow : public Weapon
{
public:
    int countbonus(Armor &a);    
    Bow(int radius, int speed);
    Bow(const Bow & copied) = delete;
    Bow & operator= (const Bow & copied) = delete;
    Bow(Bow && moved);
    Bow & operator= (Bow && moved); 
};

class Hammer : public Weapon
{
public:
    int countbonus(Armor &a);    
    Hammer(int radius, int speed);
    Hammer(const Hammer & copied) = delete;
    Hammer & operator= (const Hammer & copied) = delete;
    Hammer(Hammer && moved);
    Hammer & operator= (Hammer && moved); 
};
