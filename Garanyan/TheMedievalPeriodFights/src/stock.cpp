#include "../include/stock.h"
void Arsenal::setArmor(std::unique_ptr<Armor> armor) {
    if (armor -> getType() == ArmorType::Unarmored) {
        throw std::logic_error("You can't");
    }
    armorStack.insert(std::pair<ArmorType, std::unique_ptr<Armor>>
                      (armor->getType(), std::move(armor)));
}

void Arsenal::setWeapon(std::unique_ptr<Weapon> weapon) {
    if (weapon -> getDamageType() == DamageType::FIST) {
        throw std::logic_error("You can't ");
    }
    weaponStack.insert(std::pair<DamageType, std::unique_ptr<Weapon>>
                      (weapon->getDamageType(), std::move(weapon)));
}

std::unique_ptr<Armor> Arsenal::getArmor(ArmorType type) {
    auto it = armorStack.find(type);
    if (it == armorStack.end())
        throw std::logic_error("No such armor in arsenal");
    std::unique_ptr<Armor> ret = std::move((*it).second);
    armorStack.erase(it);
    return ret;
}

std::unique_ptr<Weapon> Arsenal::getWeapon(DamageType type) {
    auto it = weaponStack.find(type);
    if (it == weaponStack.end())
        throw std::logic_error("No such weapon in arsenal");
    std::unique_ptr<Weapon> ret = std::move((*it).second);
    weaponStack.erase(it);
    return ret;
}
