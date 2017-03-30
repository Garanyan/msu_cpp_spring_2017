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
    void enter(std::unique_ptr<Human> human)
    {
        std::string name = human->name;
        people[name].swap(human);
    }
    template <class profession = Human>
    std::unique_ptr<profession> leave(std::string name)
    {
        profession * freehuman = people[name].release();
        people.erase(name);
        return std::move(std::unique_ptr<profession>(freehuman));
    }
    bool Isinside(std::string human_name);
    void heal(std::string name);
    Location(const Location & copied) = delete;
    Location & operator= (const Location & copied) = delete;
    // Location(Location && moved);
    // Location & operator= (Location && moved);
    virtual ~Location(); 
};

class Barrack : public Location
{
public:
    Barrack() = default;
    template <class profession>
    std::string birth()
    {
        profession* human = new profession();
        std::string name = human->name;
        people[name].reset(human);
        return name;
    }
    Barrack(const Barrack & copied) = delete;
    Barrack & operator= (const Barrack & copied) = delete;
    // Barrack(Barrack && moved);
    // Barrack & operator= (Barrack && moved); 
};

class Arsenal : public Location
{
    std::map<ArmorName, int> armors;
    std::map<WeaponName, int> weapons;
public:
    Arsenal() = default;
    void addarmor(ArmorName armorname)
    {
        armors[armorname]++;
    }
    void addweapon(WeaponName weaponname)
    {
        weapons[weaponname]++;
    }
    template <class armortype>
    void takearmor(std::string human_name)
    {
        auto armor_it = armors.find(armortype::name);
        if (armor_it != armors.end() && armor_it->second > 0) {
            std::unique_ptr<armortype> armor(new armortype);
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
        auto weapon_it = weapons.find(weapontype::name);
        if (weapon_it != weapons.end() && weapon_it->second > 0) {
            std::unique_ptr<weapontype> weapon(new weapontype);
            if (this->Isinside(human_name)) {
                people[human_name]->weapon.reset(weapon);
            } else {
                throw std::logic_error{"No human in Arsenal"};
            }
        } else {
            throw std::logic_error{"No weapon in Arsenal"};
        }
    }
    void putarmor(std::string human_name)
    {
        if (this->Isinside(human_name)) {
            armors[people[human_name]->armor->getname()]++;
            people[human_name]->armor.reset(new class Torso());
        } else {
            throw std::logic_error{"No human in Arsenal"};
        }
    }
    void putweapon(std::string human_name)
    {
        if (this->Isinside(human_name)) {
            weapons[people[human_name]->weapon->getname()]++;
            people[human_name]->weapon.reset(new class Nothing());
        } else {
            throw std::logic_error{"No human in Arsenal"};
        }
    }
};

class Stadium : public Location
{
public:
    Stadium() = default;
    std::string battle(std::string human_name, std::string opponent_name);
};
