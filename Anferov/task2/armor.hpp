//Система информации об автобусных рейсах и билетах
//  armor.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef armor_hpp
#define armor_hpp

#include <map>
#include "weapon_enum.h"
#include "armor_enum.h"

class armor {
    armor_type type;
    std::map<weapon_type, double>  protection;
    double speed_fine;
    
    armor(armor const &) = delete;
    armor & operator= (armor const &) = delete;
};

class chain_armour: public armor
{
};

class lat: public armor
{
};

#endif /* armor_hpp */
