
#include"person.h"

Knight::Knight(const std::string& charName, DamageType weapon, ArmorType armor): name(charName),
                                            healthPoints(200),
                                            strength(100),
                                            speed(50),
                                            agility(40){

    charArmor = new armor;
    charWeapon = new weapon;
}

Sharp::Sharp(const std::string& charName, DamageType weapon, ArmorType armor): name(charName),
                                            healthPoints(200),
                                            strength(90),
                                            speed(60),
                                            agility(50){

    charArmor = new armor;
    charWeapon = new weapon;
}

Peasant::Peasant(const std::string& charName, DamageType weapon, ArmorType armor): name(charName),
                                            healthPoints(200),
                                            strength(80),
                                            speed(6),
                                            agility(5){

    charArmor = new armor;
    charWeapon = new weapon;
}

void person::attacked(person& enemy){
    healthPoints-=enemy->weapon.getDamage(armor)/(agility+speed);
}
