//
//  arsenal.cpp
//  C++ project
//
//  Created by Игорь Анфёров on 18.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#include "arsenal.hpp"

void arsenal::put_armor(std::unique_ptr<armor> a) {
    if (a -> get_type() == HAND) {
        throw std::logic_error("You can't put your hands to arsenal");
    }
    armor_rack.insert(std::pair<armor_type, std::unique_ptr<armor>>
                      (a->get_type(), std::move(a)));
}

void arsenal::put_weapon(std::unique_ptr<weapon> a) {
    if (a -> get_type() == FIST) {
        throw std::logic_error("You can't put your fists to arsenal");
    }
    weapon_rack.insert(std::pair<weapon_type, std::unique_ptr<weapon>>
                      (a->get_type(), std::move(a)));
}

std::unique_ptr<armor> arsenal::get_armor(armor_type t) {
    auto it = armor_rack.find(t);
    if (it == armor_rack.end())
        throw std::logic_error("No such armor in arsenal");
    std::unique_ptr<armor> ret = std::move((*it).second);
    armor_rack.erase(it);
    return ret;
}

std::unique_ptr<weapon> arsenal::get_weapon(weapon_type t) {
    auto it = weapon_rack.find(t);
    if (it == weapon_rack.end())
        throw std::logic_error("No such weapon in arsenal");
    std::unique_ptr<weapon> ret = std::move((*it).second);
    weapon_rack.erase(it);
    return ret;
}
