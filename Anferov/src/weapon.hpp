//
//  weapon.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef weapon_hpp
#define weapon_hpp

#include <iostream>
#include "armor.hpp"
#include "weapon_enum.h"

/************************* PARENT *************************/

class weapon
{
protected:
    double speed;
    double distance;
    weapon_type type;
    
    weapon(weapon const &) = delete;
    weapon & operator= (weapon const &) = delete;
    
public:
    weapon() = default;
    virtual ~weapon() = default;
    weapon(weapon &&) = default;
    weapon & operator= (weapon &&) = default;
    
    virtual double punching_ability(armor &) = 0;
    weapon_type get_type();
};

/************************ CHILDREN ************************/

class fist: public weapon
{
public:
    fist();
    virtual double punching_ability(armor &) override;
};

class shovel: public weapon
{
public:
    shovel();
    virtual double punching_ability(armor &) override;
};

class sword: public weapon
{
public:
    sword();
    virtual double punching_ability(armor &) override;
};

class hammer: public weapon
{
public:
    hammer();
    virtual double punching_ability(armor &) override;
};

class bow: public weapon
{
public:
    bow();
    virtual double punching_ability(armor &) override;
};

#endif /* weapon_hpp */
