//
//  character.hpp
//  C++ project
//
//  Created by Игорь Анфёров on 04.03.2017.
//  Copyright © 2017 Игорь Анфёров. All rights reserved.
//

#ifndef character_hpp
#define character_hpp

#include <string>
#include <memory>
#include <stdexcept>
#include "weapon.hpp"
#include "armor.hpp"

/************************* PARENT *************************/

class character
{
protected:
    std::string name;
    double health;
    double strength;
    double endurance;
    double speed;
    std::unique_ptr<weapon> curr_weapon;
    std::unique_ptr<armor>  curr_armor;
    
    character(character const &) = delete;
    character & operator= (character const &) = delete;
    
public:
    explicit character(const std::string & n);
    character(character &&) = default;
    character & operator= (character &&) = default;
    virtual ~character() = default;
    
    const std::string & get_name();
    
    void put_on_armor(std::unique_ptr<armor>);
    void take_weapon(std::unique_ptr<weapon>);
    
    std::unique_ptr<armor> take_off_armor();
    std::unique_ptr<weapon> give_weapon();
    
    void attack(character &);
    
    double get_health();
    
    virtual double skill(weapon &) = 0;
    
    std::string get_weapon_name();
    std::string get_armor_name();
};

/************************ CHILDREN ************************/

class peasant: public character
{
public:
    peasant(const std::string &);
    virtual double skill(weapon &) override;
};

class archer: public character
{
public:
    archer(const std::string &);
    virtual double skill(weapon &) override;
};

class knight: public character
{
public:
    knight(const std::string &);
    virtual double skill(weapon &) override;
};

class horseman: public character
{
public:
    horseman(const std::string &);
    virtual double skill(weapon &) override;
};

#endif /* character_hpp */
