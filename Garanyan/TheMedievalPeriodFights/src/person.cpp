#include"../include/person.h"

Person::Person(const std::string& charName): name(charName),
                                            healthPoints(200),
                                            charArmor(new Naked()),
                                            charWeapon(new Fist())
{}

Sharp::Sharp(const std::string& charName) : Person(charName){
	strength=90;
	speed=6;
	agility = 5;
}

Peasant::Peasant(const std::string& charName): Person(charName) {
	strength = 80;
	speed = 2;
	agility = 1;
}

Knight::Knight(const std::string& charName): Person(charName){
	strength = 200;
	speed = 4;
	agility = 3;
}

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

Points Person::getHP() {
	return healthPoints;
}

DamageType Person::getWeaponType()const {
	return charWeapon->getDamageType();
}

std::string Person::getName() {
	return name;
}

void Knight::attack(Person& enemy){
    healthPoints-= charArmor->getProtection(enemy.getWeaponType()) /(agility+speed);
}

void Peasant::attack(Person& enemy) {
	healthPoints -= charArmor->getProtection(enemy.getWeaponType()) / (agility + speed);
}

void Sharp::attack(Person& enemy) {
	healthPoints -= charArmor->getProtection(enemy.getWeaponType()) / (agility + speed);
}
