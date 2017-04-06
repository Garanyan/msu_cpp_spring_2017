#pragma once
#include "include.h"
#include "Human.h"

class Weapon;
class Armor;

class Location
{
public:
    std::map<std::string, std::unique_ptr<Human>> people;
    Location() = default;
    void enter(std::unique_ptr<Human> human);
    std::unique_ptr<Human> leave(std::string name);
    bool Isinside(std::string human_name);
    void heal(std::string name);
    Location(const Location & copied) = delete;
    Location & operator= (const Location & copied) = delete;
    virtual ~Location(); 
};

class Barrack : public Location
{
public:
    Barrack() = default;
    template <class profession>
    std::string birth(std::string birthname = "default")
    {
        profession* human = new profession(birthname);
        std::string name = human->name;
        people[name].reset(human);
        return name;
    }
    Barrack(const Barrack & copied) = delete;
    Barrack & operator= (const Barrack & copied) = delete;
};

class Arsenal : public Location
{
    std::map<ArmorName, int> armors;
    std::map<WeaponName, int> weapons;
public:
    Arsenal() = default;
    void addarmor(ArmorName armorname);
    void addweapon(WeaponName weaponname);
    template <class armortype>
    void takearmor(std::string human_name)
    {
        auto at = armortype::name;
        auto armor_it = armors.find(at);
        if (armor_it != armors.end() && armor_it->second > 0) {
            Armor* armor(new armortype);
            if (this->Isinside(human_name)) {
                people[human_name]->armor.reset(armor);
            } else {
                throw std::logic_error{"No human in Arsenal"};
            }
        } else {
            throw std::logic_error{"No armor in Arsenal"};
        }
    }
    template <class weapontype>
    void takeweapon(std::string human_name)
    {
        auto wt = weapontype::name;
        auto weapon_it = weapons.find(wt);
        if (weapon_it != weapons.end() && weapon_it->second > 0) {
            Weapon* weapon(new weapontype);
            if (this->Isinside(human_name)) {
                people[human_name]->weapon.reset(weapon);
            } else {
                throw std::logic_error{"No human in Arsenal"};
            }
        } else {
            throw std::logic_error{"No weapon in Arsenal"};
        }
    }
    void putarmor(std::string human_name);
    void putweapon(std::string human_name);
};

class Stadium : public Location
{
public:
    Stadium() = default;
    std::string battle(std::string human_name, std::string opponent_name);
};
