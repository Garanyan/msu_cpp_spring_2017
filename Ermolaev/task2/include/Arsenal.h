#pragma once

#include "Weapon.h"
#include "Armor.h"
#include "stdafx.h"

// Arsenal
class Arsenal
{
public:
    std::unique_ptr<Weapon> getWeapon();
    std::unique_ptr<Armor> getArmor();
    void putArmor(std::unique_ptr<Armor>&& armor);
    void putWeapon(std::unique_ptr<Weapon>&& weapon);
    void addRandomArmor();
    void addRandomWeapon();
private:
    template <class T>
    std::unique_ptr<T> make();
    std::vector<std::unique_ptr<Weapon>> weapons_;
    std::vector<std::unique_ptr<Armor>> armors_;
};
