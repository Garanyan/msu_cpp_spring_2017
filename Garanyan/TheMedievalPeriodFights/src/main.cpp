#include "../include/arena.h"
#include "../include/person.h"
#include "../include/stock.h"
//#include "../include/armor.h"
//#include "../include/weapon.h"

int main(){

	Arsenal arsenal;

    arsenal.setArmor(std::unique_ptr<Armor>(new FullPlateArmor));
    arsenal.setArmor(std::unique_ptr<Armor>(new LightSuit));
    arsenal.setWeapon(std::unique_ptr<Weapon>(new Bow));
    arsenal.setWeapon(std::unique_ptr<Weapon>(new Sword));

    Barrack barrack;
    barrack.addUnit(std::unique_ptr<Person>(new Knight("John")));
    barrack.addUnit(std::unique_ptr<Person>(new Peasant("Mike")));

	barrack["Mike"].setArmor(arsenal.getArmor(ArmorType::Plates));
	barrack["John"].setArmor(arsenal.getArmor(ArmorType::Chains));
	barrack["Mike"].setWeapon(arsenal.getWeapon(DamageType::BOW));
	barrack["John"].setWeapon(arsenal.getWeapon(DamageType::SWORD));

    std::cout <<"Mike["<< barrack["Mike"].getHP()<<"] attack John["<< barrack["John"].getHP()<<"]\n";
    barrack["John"].attack(barrack["Mike"]);
	std::cout << "John[" << barrack["John"].getHP() << "] fights with Mike[" << barrack["Mike"].getHP() << "]\n";
	barrack.battleToDeath(barrack["John"], barrack["Mike"]);
	std::cout << "John[" << barrack["John"].getHP() << "] and Mike[" << barrack["Mike"].getHP() << "]\n";

}
