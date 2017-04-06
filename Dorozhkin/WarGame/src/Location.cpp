#pragma once
#include "../include/Location.h"

//Location
void Location::enter(std::unique_ptr<Human> human)
{
    std::string name = human->name;
    people[name].swap(human);
}

std::unique_ptr<Human> Location::leave(std::string name)
{
    Human * freehuman = people[name].release();
    people.erase(name);
    return std::move(std::unique_ptr<Human>(freehuman));
}

Location::~Location()
{
    
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
        people[name]->life = 100;
    } else {
        throw std::logic_error{"No human in Location"};
    }
}

//Barrack

//Arsenal
void Arsenal::addarmor(ArmorName armorname)
{
    armors[armorname]++;
}

void Arsenal::addweapon(WeaponName weaponname)
{
    weapons[weaponname]++;
}

void Arsenal::putarmor(std::string human_name)
{
    if (this->Isinside(human_name)) {
        armors[people[human_name]->armor->getname()]++;
        people[human_name]->armor.reset(new class Torso());
    } else {
        throw std::logic_error{"No human in Arsenal"};
    }
}

void Arsenal::putweapon(std::string human_name)
{
    if (this->Isinside(human_name)) {
        weapons[people[human_name]->weapon->getname()]++;
        people[human_name]->weapon.reset(new class Nothing());
    } else {
        throw std::logic_error{"No human in Arsenal"};
    }
}



//Stadium
std::string Stadium::battle(std::string human_name, std::string opponent_name)
{
    if (this->Isinside(human_name) && this->Isinside(opponent_name)) {
        while (people[human_name]->life >= 0 && people[opponent_name]->life >= 0)
        {
            
            auto human_damage = people[human_name]->takedamage(people[opponent_name]);
            auto opponent_damage = people[opponent_name]->takedamage(people[human_name]);
            std::cout << human_damage << std::endl;
            std::cout << opponent_damage << std::endl;
            people[human_name]->life -= human_damage > 0 ? human_damage : 0;
            people[opponent_name]->life -= opponent_damage > 0 ? opponent_damage : 0;
        }
        return people[human_name]->life > 0 ? human_name : opponent_name;
    } else {
        throw std::logic_error{"No human in Stadium"};
    }
}
