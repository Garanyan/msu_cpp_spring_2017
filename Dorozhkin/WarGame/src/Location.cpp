#pragma once
#include "../include/Location.h"
#include "stdafx.h"

//Location
const std::string& Location::enter(std::unique_ptr<Human>&& human)
{
    std::string name = human->name_;
    people[name].swap(human);
    return people[name]->name_;
}

std::unique_ptr<Human> Location::leave(const std::string& name)
{
    Human* freehuman = people[name].release();
    people.erase(name);
    return std::move(std::unique_ptr<Human>(freehuman));
}

Location::~Location()
{
    
}

bool Location::isInside(const std::string& humanName) const
{
    if (people.find(humanName) != people.end()) {
        return true;
    } else {
        return false;
    }
}

void Location::heal(const std::string& name)
{
    if (this->isInside(name)) {
        people[name]->life_ = people[name]->getDefaultLife();
    } else {
        throw std::logic_error{"No human in Location"};
    }
}

//Barrack

//Arsenal
void Arsenal::addArmor(const ArmorName& armorName)
{
    armors[armorName]++;
}

void Arsenal::addWeapon(const WeaponName& weaponName)
{
    weapons[weaponName]++;
}

void Arsenal::putArmor(const std::string& humanName)
{
    if (this->isInside(humanName)) {
        armors[people[humanName]->armor_->getName()]++;
        people[humanName]->armor_.reset(new class Torso());
    } else {
        throw std::logic_error{"No human in Arsenal"};
    }
}

void Arsenal::putWeapon(const std::string& humanName)
{
    if (this->isInside(humanName)) {
        weapons[people[humanName]->weapon_->getName()]++;
        people[humanName]->weapon_.reset(new class Nothing());
    } else {
        throw std::logic_error{"No human in Arsenal"};
    }
}



//Stadium
const std::string& Stadium::battle(const std::string& humanName, const std::string& opponentName)
{
    if (this->isInside(humanName) && this->isInside(opponentName)) {
        while (people[humanName]->life_ >= 0 && people[opponentName]->life_ >= 0)
        {
            
            auto humanDamage = people[humanName]->takeDamage(*people[opponentName]);
            auto opponentDamage = people[opponentName]->takeDamage(*people[humanName]);
            people[humanName]->life_ -= humanDamage > 0 ? humanDamage : 0;
            people[opponentName]->life_ -= opponentDamage > 0 ? opponentDamage : 0;
        }
        return people[humanName]->life_ > 0 ? humanName : opponentName;
    } else {
        throw std::logic_error{"No human in Stadium"};
    }
}
