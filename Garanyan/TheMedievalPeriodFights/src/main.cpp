#include "../include/arena.h"
#include "../include/person.h"
#include "../include/stock.h"
#include <string>

int main(){

	Arsenal arsenal;

    for(int i=0; i<5; i++){
        arsenal.setWeapon(std::unique_ptr<Weapon>(new Bow));
        arsenal.setWeapon(std::unique_ptr<Weapon>(new Sword));
        arsenal.setWeapon(std::unique_ptr<Weapon>(new Hammer));
    }

    arsenal.setArmor(std::unique_ptr<Armor>(new FullPlateArmor));
    for(int i=0; i<7; i++){
        arsenal.setArmor(std::unique_ptr<Armor>(new FullPlateArmor));
        arsenal.setArmor(std::unique_ptr<Armor>(new LightSuit));
    }
    Barrack barrack;
    for(int i=0; i<20; i++){
        barrack.addUnit(std::unique_ptr<Person>(new Knight(std::to_string(i))));
    }




	barrack["0"].setArmor(arsenal.getArmor(ArmorType::Plates));
	barrack["1"].setArmor(arsenal.getArmor(ArmorType::Chains));
	barrack["0"].setWeapon(arsenal.getWeapon(DamageType::BOW));
	barrack["1"].setWeapon(arsenal.getWeapon(DamageType::SWORD));

    std::cout <<"0["<< barrack["0"].getHP()<<"] attack 1["<< barrack["1"].getHP()<<"]\n";
    barrack["1"].attack(barrack["0"]);
	std::cout << "1[" << barrack["1"].getHP() << "] fights with 0[" << barrack["0"].getHP() << "]\n";
	barrack.battleToDeath(barrack["1"], barrack["0"]);
	std::cout << "1[" << barrack["1"].getHP() << "] and 0[" << barrack["0"].getHP() << "]\n";

}
