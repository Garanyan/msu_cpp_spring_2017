
#pragma once
#include <map>
#include "armor.h"
#include "weapon.h"

class Arsenal{
private:
    std::map<ArmorType, int> armory;
    std::map<WeaponType, int> weaponary;
    std::unique_ptr <Armor> createLats();
    std::unique_ptr <Armor> createCorslet();
    std::unique_ptr <Armor> createNoArmor();
    std::unique_ptr <Weapon> createBow();
    std::unique_ptr <Weapon> createSword();
    std::unique_ptr <Weapon> createShovel();
    std::unique_ptr <Weapon> createFists();
public:
    Arsenal();
    ~Arsenal() = default;
    bool anyLats() const;
    bool anyCorslet() const;
    bool anyBow() const;
    bool anySword() const;
    bool anyShovel() const;
    std::unique_ptr <Armor> useLats();
    std::unique_ptr <Armor> useCorslet();
    std::unique_ptr <Armor> unArmored();
    std::unique_ptr <Weapon> useBow();
    std::unique_ptr <Weapon> useSword();
    std::unique_ptr <Weapon> useShovel();
    std::unique_ptr <Weapon> useFists();
};
