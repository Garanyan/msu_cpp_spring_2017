
#include"person.h"

Person::Person(const std::string& charName): name(charName),
                                            healthPoints(200),
                                            charArmor(new Naked()),
                                            charWeapon(new Fist())
{}

Sharp::Sharp(const std::string& charName, DamageType weapon, ArmorType armor):
                                            Person(charName),
                                            strength(90),
                                            speed(60),
                                            agility(50)
{}

Peasant::Peasant(const std::string& charName, DamageType weapon, ArmorType armor):
                                            Person(charName),
                                            strength(80),
                                            speed(6),
                                            agility(5)
{}

Knight::Knight(const std::string& charName, DamageType weapon, ArmorType armor):
                                            Person(charName),
                                            strength(200),
                                            speed(40),
                                            agility(6)
{}

void Person::setWeapon(std::unique_ptr<Weapon> weapon){
         if(charWeapon->getWeaponType() == FIST)
            charWeapon = std::move(weapon);
}
void Person::setArmor(std::unique_ptr<Armor> armor){
	     if(charArmor->getType() == Unarmored)
            charArmor = std::move(armor);
}

std::unique_ptr<Armor> character::takeOffArmor() {
    if (curr_armor -> getType() == Unarmored) {
        throw std::logic_error(name + " has no armor");
    }
    std::unique_ptr<Armor> ret = std::move(curr_armor);
    curr_armor.reset(new Naked());
    return ret;
}

std::unique_ptr<Weapon> character::give_weapon() {
    if (curr_weapon -> getWeaponType() == FIST) {
        throw std::logic_error(name + " has no weapon");
    }
    std::unique_ptr<Weapon> ret = std::move(curr_weapon);
    curr_weapon.reset(new Fist());
    return ret;
}

void person::attacked(person& enemy){
    healthPoints-=enemy->weapon.getDamage(armor)/(agility+speed);
}
