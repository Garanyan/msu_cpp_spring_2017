//
//  weapon.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef weapon_hpp
#define weapon_hpp

#include <map>
#include "weapon_enum.h"
#include "armor_enum.h"

class weapon
{
    weapon_type type;
    std::map<armor_type, double> punching_ability;
    double speed;
    double distance;
    
    weapon(weapon const &) = delete;
    weapon & operator= (weapon const &) = delete;
};

class fist: public weapon
{
};

class shovel: public weapon
{
};

class sword: public weapon
{
};

class hammer: public weapon
{
};

class bow: public weapon
{
};

#endif /* weapon_hpp */
