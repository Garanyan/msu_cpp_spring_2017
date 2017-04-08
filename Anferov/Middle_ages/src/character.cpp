//
//  character.cpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#include "character.hpp"

/************************* PARENT *************************/

character::character(const std::string & s) : name(s),
                                            health(10),
                                            curr_weapon(new fist()),
                                            curr_armor(new hand()) {}

const std::string & character::get_name() {
    return name;
}

void character::put_on_armor(std::unique_ptr<armor> a) {
    if (curr_armor -> get_type() != HAND) {
        throw std::logic_error(name + " already has armor");
    }
    curr_armor = std::move(a);
}

void character::take_weapon(std::unique_ptr<weapon> a) {
    if (curr_weapon -> get_type() != FIST) {
        throw std::logic_error(name + " already has weapon");
    }
    curr_weapon = std::move(a);
}

std::unique_ptr<armor> character::take_off_armor() {
    if (curr_armor -> get_type() == HAND) {
        throw std::logic_error(name + " has no armor");
    }
    std::unique_ptr<armor> ret = std::move(curr_armor);
    curr_armor.reset(new hand());
    return ret;
}

std::unique_ptr<weapon> character::give_weapon() {
    if (curr_weapon -> get_type() == FIST) {
        throw std::logic_error(name + " has no weapon");
    }
    std::unique_ptr<weapon> ret = std::move(curr_weapon);
    curr_weapon.reset(new fist());
    return ret;
}

void character::attack(character &c) {
    c.health -= curr_weapon->punching_ability(*(c.curr_armor)) *
                (skill(*curr_weapon)/10) * strength/10;
}

double character::get_health() {
    return health;
}

/************************ CHILDREN ************************/

peasant::peasant(const std::string & s): character(s) {
    strength = 5;
    endurance = 5;
    speed = 5;
}

double peasant::skill(weapon &a) {
    if (a.get_type() == FIST  ) return 5;
    if (a.get_type() == SHOVEL) return 8;
    if (a.get_type() == SWORD ) return 3;
    if (a.get_type() == HAMMER) return 3;
    if (a.get_type() == BOW   ) return 1;
    throw std::logic_error("Unrecognized weapon type");
}

archer::archer(const std::string & s): character(s) {
    strength = 7;
    endurance = 8;
    speed = 8;
}

double archer::skill(weapon &a) {
    if (a.get_type() == FIST  ) return 7;
    if (a.get_type() == SHOVEL) return 4;
    if (a.get_type() == SWORD ) return 5;
    if (a.get_type() == HAMMER) return 4;
    if (a.get_type() == BOW   ) return 10;
    throw std::logic_error("Unrecognized weapon type");
}

knight::knight(const std::string & s): character(s) {
    strength = 10;
    endurance = 10;
    speed = 10;
}

double knight::skill(weapon &a) {
    if (a.get_type() == FIST  ) return 8;
    if (a.get_type() == SHOVEL) return 4;
    if (a.get_type() == SWORD ) return 10;
    if (a.get_type() == HAMMER) return 7;
    if (a.get_type() == BOW   ) return 4;
    throw std::logic_error("Unrecognized weapon type");
}
