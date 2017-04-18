#pragma once
// #include "include.h"
#include "Human.h"

class Weapon;
class Armor;

class Location
{
public:
    std::map<std::string, std::unique_ptr<Human>> people;
    Location() = default;
    const std::string& enter(std::unique_ptr<Human>&& human);
    std::unique_ptr<Human> leave(const std::string& name);
    bool isInside(const std::string& humanName) const;
    void heal(const std::string& name);
    Location(const Location& copied) = delete;
    Location& operator= (const Location& copied) = delete;
    virtual ~Location(); 
};

class Barrack : public Location
{
public:
    Barrack() = default;
    template <class profession>
    std::string birth(const std::string& birthName = "default")
    {
        auto human = std::unique_ptr<Human>(new profession(birthName));
        std::string name = human->name_;
        people[name].swap(human);
        return name;
    }
    Barrack(const Barrack& copied) = delete;
    Barrack& operator= (const Barrack& copied) = delete;
};

class Arsenal : public Location
{
    std::map<ArmorName, int> armors;
    std::map<WeaponName, int> weapons;
public:
    void addArmor(const ArmorName& armorName);
    Arsenal() = default;
    void addWeapon(const WeaponName& weaponName);
    template <class armorType>
    void takeArmor(const std::string& humanName)
    {
        auto at = armorType::name;
        auto armor_it = armors.find(at);
        if (armor_it != armors.end()&& armor_it->second > 0) {
            auto armor = std::unique_ptr<Armor>(new armorType);
            if (this->isInside(humanName)) {
                people[humanName]->armor_.swap(armor);
            } else {
                throw std::logic_error{"No human in Arsenal"};
            }
        } else {
            throw std::logic_error{"No armor in Arsenal"};
        }
    }
    template <class weaponType>
    void takeWeapon(const std::string& humanName)
    {
        auto wt = weaponType::name;
        auto weapon_it = weapons.find(wt);
        if (weapon_it != weapons.end()&& weapon_it->second > 0) {
            auto weapon = std::unique_ptr<Weapon>(new weaponType);
            if (this->isInside(humanName)) {
                people[humanName]->weapon_.swap(weapon);
            } else {
                throw std::logic_error{"No human in Arsenal"};
            }
        } else {
            throw std::logic_error{"No weapon in Arsenal"};
        }
    }
    void putArmor(const std::string& humanName);
    void putWeapon(const std::string& humanName);
};

class Stadium : public Location
{
public:
    Stadium() = default;
    const std::string& battle(const std::string& human_name, const std::string& opponent_name);
};
