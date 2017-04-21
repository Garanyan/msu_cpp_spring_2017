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

    std::cout <<"John attack Mike \n";
    barrack["Mike"].attacked(barrack["John"]);
    std::cout << barrack["Jack"].getHealth() << std::endl;

}
