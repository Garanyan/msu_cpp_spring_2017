void Arsenal::putArmor(std::unique_ptr<Armor> armor) {
    if (armor -> getType() == Unarmored) {
        throw std::logic_error("You can't");
    }
    armorStack.insert(std::pair<ArmorType, std::unique_ptr<Armor>>
                      (armor->get_type(), std::move(armor)));
}

void Arsenal::putWeapon(std::unique_ptr<Weapon> weapon) {
    if (weapon -> getWeaponType() == FIST) {
        throw std::logic_error("You can't put your fists to arsenal");
    }
    weaponStack.insert(std::pair<WeaponType, std::unique_ptr<Weapon>>
                      (weapon->get_type(), std::move(weapon)));
}

std::unique_ptr<Armor> Arsenal::setArmor(ArmorType type) {
    auto it = armorStack.find(type);
    if (it == armorStack.end())
        throw std::logic_error("No such armor in arsenal");
    std::unique_ptr<Armor> ret = std::move((*it).second);
    armorStack.erase(it);
    return ret;
}

std::unique_ptr<Weapon> arsenal::setWeapon(WeaponType type) {
    auto it = weaponStack.find(type);
    if (it == weaponStack.end())
        throw std::logic_error("No such weapon in arsenal");
    std::unique_ptr<Weapon> ret = std::move((*it).second);
    weaponStack.erase(it);
    return ret;
}
