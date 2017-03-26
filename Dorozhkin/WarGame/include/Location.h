#pragma once
#include "include.h"
#include "Human.h"

class Weapon;
class Armor;

class Location
{
    std::map<std::string, Human> people;
public:
    Location() = default;
    void enter(Human &human);
    Human&& leave(std::string name);
    Location(const Location & copied) = delete;
    Location & operator= (const Location & copied) = delete;
    Location(Location && moved);
    Location & operator= (Location && moved); 
};

class Barrack : public Location
{
public:
    Barrack() = default;
    Human& heal(Human &human);
    template <class profession>
    profession& birth();
    Barrack(const Barrack & copied) = delete;
    Barrack & operator= (const Barrack & copied) = delete;
    Barrack(Barrack && moved);
    Barrack & operator= (Barrack && moved); 
};

class Arsenal : public Location
{
    std::map<const char*, int> armors;
    std::map<const char*, int> weapons;
public:
    Arsenal() = default;
    template <class armortype>
    void addarmor();
    template <class weapontype>
    void addweapon();
    template <class armortype>
    Armor&& takearmor();
    template <class weapontype>
    Weapon&& takeweapon();
    template <class armortype>
    void putarmor(armortype &&armor);
    template <class weapontype>
    void putweapon(weapontype &&weapon);
};

class Stadium : public Location
{
public:
    Stadium() = default;
    Human& battle(Human &human, Human &opponent);
};
