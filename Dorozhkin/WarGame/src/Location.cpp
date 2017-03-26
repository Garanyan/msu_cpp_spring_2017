#pragma once
#include "../include/Location.h"

//Location
void Location::enter(Human &human)
{
    std::string name = human.name;
    people[name] = std::move(human);
}

Human&& Location::leave(std::string name)
{
    Human freehuman = std::move(people[name]);
    people.erase(name);
    return std::move(freehuman);
}

//Barrack
Human& Barrack::heal(Human &human)
{
    human.life = 100;
    return human;
}

template <class profession>
profession& Barrack::birth()
{
    profession human{};
    return human;
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
Armor&& Arsenal::takearmor()
{
    auto armor_it = armors.find(armortype::name);
    if (armor_it != armors.end() && *armor_it > 0) {
        armortype armor{};
        return std::move(armor);
    } else {
        throw 1;
    }
}

template <class weapontype>
Weapon&& Arsenal::takeweapon()
{
    auto weapon_it = weapons.find(weapontype::name);
    if (weapon_it != weapons.end() && *weapon_it > 0) {
        weapontype weapon{};
        return std::move(weapon);
    } else {
        throw 1;
    }
}

template <class armortype>
void Arsenal::putarmor(armortype &&armor)
{
    armors[armortype::name]++;
}

template <class weapontype>
void Arsenal::putweapon(weapontype &&weapon)
{
    weapons[weapontype::name]++;
}

//Stadium
Human& Stadium::battle(Human &human, Human &opponent)
{
    while (human.life >= 0 && opponent.life >= 0)
    {
        human.life -= 2;
        opponent.life -= 1;
    }
    return human.life <= 0 ? opponent : human;
}
