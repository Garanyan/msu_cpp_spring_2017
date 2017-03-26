#pragma once
#include "include.h"
#include "Human.h"

class Weapon;
class Armor;

class Location
{
public:
    std::map<std::string, Human> people;
    Location() = default;
    template <class profession>
    void enter(profession &&human);
    template <class profession>
    profession&& leave(std::string name);
    bool Isinside(std::string human_name);
    void heal(std::string name);
    Location(const Location & copied) = delete;
    Location & operator= (const Location & copied) = delete;
    Location(Location && moved);
    Location & operator= (Location && moved); 
};

class Barrack : public Location
{
public:
    Barrack() = default;
    template <class profession>
    std::string birth();
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
    void takearmor(std::string human_name);
    template <class weapontype>
    void takeweapon(std::string human_name);
    template <class armortype>
    void putarmor(std::string human_name);
    template <class weapontype>
    void putweapon(std::string human_name);
};

class Stadium : public Location
{
public:
    Stadium() = default;
    std::string battle(std::string human_name, std::string opponent_name);
};
