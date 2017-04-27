#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

#include <map>
#include "../include/armor.h"
#include "../include/weapon.h"
#include <memory>

class Arsenal
{
    std::multimap<ArmorType, std::unique_ptr<Armor>> armorStack;
    std::multimap<DamageType, std::unique_ptr<Weapon>> weaponStack;

    Arsenal(Arsenal const &) = delete;
    Arsenal & operator= (Arsenal const &) = delete;

public:
    Arsenal()=default ;
    virtual ~Arsenal() =default;
    void setArmor(std::unique_ptr<Armor>);
    void setWeapon(std::unique_ptr<Weapon>);
    std::unique_ptr<Armor> getArmor(ArmorType);
    std::unique_ptr<Weapon> getWeapon(DamageType);
};

#endif // STOCK_H_INCLUDED
