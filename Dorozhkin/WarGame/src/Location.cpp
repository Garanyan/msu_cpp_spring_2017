#pragma once
#include "../include/Location.h"

//Location
template <class profession>
void Location::enter(profession &&human)
{
    std::string name = human.name;
    people[name] = std::move(human);
}
template <class profession>
profession&& Location::leave(std::string name)
{
    profession freehuman = std::move(people[name]);
    people.erase(name);
    return std::move(freehuman);
}

bool Location::Isinside(std::string human_name)
{
    if (people.find(human_name) != people.end()) {
        return true;
    } else {
        return false;
    }
}

void Location::heal(std::string name)
{
    if (this->Isinside(name)) {
        people[name].life = 100;
    } else {
        throw "No human in Location";
    }
}

//Barrack
template <class profession>
std::string Barrack::birth()
{
    profession human{};
    std::string name = human.name;
    people[name] = std::move(human);
    return name;
}

//Arsenal
template <class armortype>
void Arsenal::addarmor()
{
    armors[armortype::name]++;
}

template <class weapontype>
void Arsenal::addweapon()
{
    weapons[weapontype::name]++;
}

template <class armortype>
void Arsenal::takearmor(std::string human_name)
{
    auto armor_it = armors.find(armortype::name);
    if (armor_it != armors.end() && *armor_it > 0) {
        armortype armor{};
        if (this->Isinside(human_name)) {
            people[human_name].armor = std::move(armor);
        } else {
            throw "No human in Arsenal";
        }
    } else {
        throw "No armor in Arsenal";
    }
}

template <class weapontype>
void Arsenal::takeweapon(std::string human_name)
{
    auto weapon_it = weapons.find(weapontype::name);
    if (weapon_it != weapons.end() && *weapon_it > 0) {
        weapontype weapon{};
        if (this->Isinside(human_name)) {
            people[human_name].weapon = std::move(weapon);
        } else {
            throw "No human in Arsenal";
        }
    } else {
        throw "No weapon in Arsenal";
    }
}

template <class armortype>
void Arsenal::putarmor(std::string human_name)
{
    if (this->Isinside(human_name)) {
        armortype armor = std::move(people[human_name].armor);
        people[human_name].armor = Torso();
        armors[armortype::name]++;
    } else {
        throw "No human in Arsenal";
    }
}

template <class weapontype>
void Arsenal::putweapon(std::string human_name)
{
    if (this->Isinside(human_name)) {
        weapontype weapon = std::move(people[human_name].weapon);
        people[human_name].weapon = Nothing();
        weapons[weapontype::name]++;
    } else {
        throw "No human in Arsenal";
    }
}

//Stadium
std::string Stadium::battle(std::string human_name, std::string opponent_name)
{
    if (this->Isinside(human_name) && this->Isinside(opponent_name)) {
        Human human = std::move(people[human_name]);
        Human opponent = std::move(people[opponent_name]);
        while (human.life >= 0 && opponent.life >= 0)
        {
            human.life -= human.takedamage(opponent);
            opponent.life -= opponent.takedamage(human);
        }
        people[human_name] = std::move(human);
        people[opponent_name] = std::move(opponent);
        return human.life > 0 ? human_name : opponent_name;
    } else {
        throw "No human in Stadium";
    }
}
