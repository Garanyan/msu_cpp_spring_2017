//
//  weapon.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef weapon_hpp
#define weapon_hpp

#include "punching_properties.hpp"

class weapon
{
public:
    punching_properties punching_ability;
    double speed;
    double distance;
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
