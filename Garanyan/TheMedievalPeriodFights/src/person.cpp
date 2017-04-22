
#include"../include/person.h"
//#include "../include/armor.h"
//#include "../include/weapon.h"

Person::Person(const std::string& charName): name(charName),
                                            healthPoints(200),
                                            charArmor(new Naked()),
                                            charWeapon(new Fist())
{}

Sharp::Sharp(const std::string& charName):
                                            Person(charName),
                                            strength(90),
                                            speed(60),
                                            agility(50)
{}

Peasant::Peasant(const std::string& charName):
                                            Person(charName),
                                            strength(80),
                                            speed(6),
                                            agility(5)
{}

Knight::Knight(const std::string& charName):
                                            Person(charName),
                                            strength(200),
                                            speed(40),
                                            agility(6)
{}

void Person::setWeapon(std::unique_ptr<Weapon> weapon){
         if(charWeapon->getDamageType() == DamageType::FIST)
            charWeapon = std::move(weapon);
}
void Person::setArmor(std::unique_ptr<Armor> armor){
	     if(charArmor->getType() == ArmorType::Unarmored)
            charArmor = std::move(armor);
}

std::unique_ptr<Armor> Person::takeOffArmor() {
    if (charArmor -> getType() == ArmorType::Unarmored) {
        throw std::logic_error(name + " has no armor");
    }
    std::unique_ptr<Armor> ret = std::move(charArmor);
    charArmor.reset(new Naked());
    return ret;
}

std::unique_ptr<Weapon> Person::takeOffWeapon() {
    if (charWeapon -> getDamageType() == DamageType::FIST) {
        throw std::logic_error(name + " has no weapon");
    }
    std::unique_ptr<Weapon> ret = std::move(charWeapon);
    charWeapon.reset(new Fist());
    return ret;
}

void Person::attacked(Person& enemy){
    healthPoints-=enemy->weapon.getDamage(charArmor)/(agility+speed);
}
