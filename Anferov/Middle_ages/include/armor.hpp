//Система информации об автобусных рейсах и билетах
//  armor.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef armor_hpp
#define armor_hpp

#include <string>
#include "weapon_light.hpp"
#include "armor_enum.h"

/************************* PARENT *************************/

class armor
{
protected:
    double speed_fine;
    armor_type type;
    
    armor(armor const &) = delete;
    armor & operator= (armor const &) = delete;
    
public:
    armor() = default;
    virtual ~armor() = default;
    armor(armor &&) = default;
    armor & operator= (armor &&) = default;
    armor_type get_type();
    std::string get_name();
};

/************************ CHILDREN ************************/

class hand: public armor
{
public:
    hand();
};

class chain_armour: public armor
{
public:
    chain_armour();
};

class lat: public armor
{
public:
    lat();
};

#endif /* armor_hpp */
