#pragma once
#include "../include/Location.h"

//Location
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

//Stadium
std::string Stadium::battle(std::string human_name, std::string opponent_name)
{
    if (this->Isinside(human_name) && this->Isinside(opponent_name)) {
        while (people[human_name]->life >= 0 && people[opponent_name]->life >= 0)
        {
            auto human_damage = people[human_name]->takedamage(people[opponent_name]);
            auto opponent_damage = people[opponent_name]->takedamage(people[human_name]);
            people[human_name]->life += human_damage < 0 ? human_damage : 0;
            people[opponent_name]->life += opponent_damage < 0 ? opponent_damage : 0;
        }
        return people[human_name]->life > 0 ? human_name : opponent_name;
    } else {
        throw std::logic_error{"No human in Stadium"};
    }
}
