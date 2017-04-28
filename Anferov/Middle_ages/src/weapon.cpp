//
//  weapon.cpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#include "weapon.hpp"

/************************* PARENT *************************/

weapon_type weapon::get_type() {
    return type;
}

std::string weapon::get_name() {
    switch (type) {
        case FIST:
            return "fist";
        case SHOVEL:
            return "shovel";
        case SWORD:
            return "sword";
        case HAMMER:
            return "hammer";
        case BOW:
            return "bow";
    }
}

/************************ CHILDREN ************************/

fist::fist(): weapon() {
    speed = 10;
    distance = 1;
    type = FIST;
}

double fist::punching_ability(armor &a) {
    if (a.get_type() == HAND        ) return 4;
    if (a.get_type() == CHAIN_ARMOUR) return 2;
    if (a.get_type() == LAT         ) return 1;
    throw std::logic_error("Unrecognized armor type");
}

shovel::shovel(): weapon() {
    speed = 6;
    distance = 2;
    type = SHOVEL;
}

double shovel::punching_ability(armor &a) {
    if (a.get_type() == HAND        ) return 6;
    if (a.get_type() == CHAIN_ARMOUR) return 4;
    if (a.get_type() == LAT         ) return 2;
    throw std::logic_error("Unrecognized armor type");
}


sword::sword(): weapon() {
    speed = 8;
    distance = 2;
    type = SWORD;
}

double sword::punching_ability(armor &a) {
    if (a.get_type() == HAND        ) return 10;
    if (a.get_type() == CHAIN_ARMOUR) return 6;
    if (a.get_type() == LAT         ) return 4;
    throw std::logic_error("Unrecognized armor type");
}

hammer::hammer(): weapon() {
    speed = 6;
    distance = 2;
    type = HAMMER;
}

double hammer::punching_ability(armor &a) {
    if (a.get_type() == HAND        ) return 10;
    if (a.get_type() == CHAIN_ARMOUR) return 7;
    if (a.get_type() == LAT         ) return 6;
    throw std::logic_error("Unrecognized armor type");
}

bow::bow(): weapon() {
    speed = 4;
    distance = 10;
    type = BOW;
}

double bow::punching_ability(armor &a) {
    if (a.get_type() == HAND        ) return 8;
    if (a.get_type() == CHAIN_ARMOUR) return 5;
    if (a.get_type() == LAT         ) return 3;
    throw std::logic_error("Unrecognized armor type");
}
