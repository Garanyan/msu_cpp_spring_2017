//
//  character.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef character_hpp
#define character_hpp

#include <map>
#include <string>
#include "weapon.hpp"
#include "armor.hpp"
#include "weapon_enum.h"

class character
{
    std::string name;
    double strength;
    double endurance;
    double speed;
    std::map<weapon_type, double> skills;
    weapon curr_weapon;
    armor curr_armor;
    
    character(character const &) = delete;
    character & operator= (character const &) = delete;
    
public:
    character & operator= (character &&) = default;
};

class peasant: public character
{
};

class archer: public character
{
};

class knight: public character
{
};

#endif /* character_hpp */
