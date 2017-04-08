//
//  arsenal.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 18.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef arsenal_hpp
#define arsenal_hpp

#include <map>
#include <memory>
#include "weapon.hpp"
#include "armor.hpp"
#include "weapon_enum.h"
#include "armor_enum.h"

class arsenal
{
    std::multimap<armor_type, std::unique_ptr<armor>> armor_rack;
    std::multimap<weapon_type, std::unique_ptr<weapon>> weapon_rack;
    
    arsenal(arsenal const &) = delete;
    arsenal & operator= (arsenal const &) = delete;
    
public:
    arsenal() = default;
    virtual ~arsenal() = default;
    void put_armor(std::unique_ptr<armor>);
    void put_weapon(std::unique_ptr<weapon>);
    std::unique_ptr<armor> get_armor(armor_type);
    std::unique_ptr<weapon> get_weapon(weapon_type);
};

#endif /* arsenal_hpp */
