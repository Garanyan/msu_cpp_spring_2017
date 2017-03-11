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

class weapon;

class armor {
    std::map<weapon *, double>  protection;
    double speed_fine;
};

class chain_armour: public armor
{
};

class lat: public armor
{
};

#endif /* armor_hpp */
