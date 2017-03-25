//
//  armor.cpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#include "armor.hpp"

/************************* PARENT *************************/

armor_type armor::get_type() {
    return type;
}

/************************ CHILDREN ************************/

hand::hand(): armor() {
    speed_fine = 0;
    type = HAND;
}

chain_armour::chain_armour(): armor() {
    speed_fine = 3;
    type = CHAIN_ARMOUR;
}

lat::lat(): armor() {
    speed_fine = 7;
    type = LAT;
}
