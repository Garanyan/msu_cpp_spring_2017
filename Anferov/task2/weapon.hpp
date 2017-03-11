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

class armor;

class weapon
{
public:
    std::map<armor *, double> punching_ability;
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
