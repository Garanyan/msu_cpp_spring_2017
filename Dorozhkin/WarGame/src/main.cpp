#pragma once 
#include "../include/Armor.h"
#include "../include/Weapon.h"
#include "../include/Location.h"
#include "../include/Human.h"
#include "../include/include.h"

int main(int argc, char const *argv[]) {
    try {
        std::unique_ptr<Barrack> barrack(new class Barrack());
        std::unique_ptr<Stadium> stadium(new class Stadium());
        std::unique_ptr<Arsenal> arsenal(new class Arsenal());
        std::string peasant_name = barrack->birth<Peasant>("Cowboy");
        std::string archer_name = barrack->birth<Archer>("Legolas");
        std::string knight_name = barrack->birth<Knight>("Uter");
        std::cout << "Peasant: " << peasant_name << std::endl;
        std::cout << "Archer: " << archer_name << std::endl;
        std::cout << "Knight: " << knight_name << std::endl;
        
        std::cout << "Adding weapons and armors to arsenal" << std::endl;
        arsenal->addarmor(ArmorName::Chain);
        arsenal->addarmor(ArmorName::Chain);
        arsenal->addarmor(ArmorName::Corslet);
        arsenal->addweapon(WeaponName::Bow);
        arsenal->addweapon(WeaponName::Shovel);
        arsenal->addweapon(WeaponName::Hammer);
        arsenal->addweapon(WeaponName::Sword);
        
        std::cout << "Leave people from barrack" << std::endl;
        std::unique_ptr<Human> peasant = barrack->leave(peasant_name);
        std::unique_ptr<Human> archer = barrack->leave(archer_name);
        std::unique_ptr<Human> knight = barrack->leave(knight_name);
        
        std::cout << "Enter people to arsenal" << std::endl;
        arsenal->enter(std::move(peasant));
        arsenal->enter(std::move(archer));
        arsenal->enter(std::move(knight));
        
        std::cout << "Weapon take" << std::endl;
        arsenal->takeweapon<Shovel>(peasant_name);
        arsenal->takeweapon<Bow>(archer_name);
        arsenal->takeweapon<Hammer>(knight_name);
        
        std::cout << "Armor take" << std::endl;
        arsenal->takearmor<Chain>(peasant_name);
        arsenal->takearmor<Chain>(archer_name);
        arsenal->takearmor<Corslet>(knight_name);
        
        std::cout << "Leave people from arsenal" << std::endl;
        peasant = arsenal->leave(peasant_name);
        archer = arsenal->leave(archer_name);
        knight = arsenal->leave(knight_name);
        
        std::cout << "Enter people to stadium" << std::endl;
        stadium->enter(std::move(peasant));
        stadium->enter(std::move(archer));
        stadium->enter(std::move(knight));
        
        std::cout << "Battle 1" << std::endl;
        std::string winner = stadium->battle(peasant_name, archer_name);
        std::cout << "Winner: " << winner << std::endl;
        stadium->heal(peasant_name);
        stadium->heal(archer_name);
        
        std::cout << "Battle 2" << std::endl;
        winner = stadium->battle(archer_name, knight_name);
        std::cout << "Winner: " << winner << std::endl;
        stadium->heal(knight_name);
        stadium->heal(archer_name);
        
        std::cout << "Battle 3" << std::endl;
        winner = stadium->battle(peasant_name, archer_name);
        std::cout << "Winner: " << winner << std::endl;
        stadium->heal(peasant_name);
        stadium->heal(archer_name);
        
        std::cout << "Leave people from stadium" << std::endl;
        peasant = stadium->leave(peasant_name);
        archer = stadium->leave(archer_name);
        knight = stadium->leave(knight_name);
        
        std::cout << "Enter people to arsenal" << std::endl;
        arsenal->enter(std::move(peasant));
        arsenal->enter(std::move(archer));
        arsenal->enter(std::move(knight));
        
        std::cout << "Put weapons back to arsenal" << std::endl;
        arsenal->putweapon(peasant_name);
        arsenal->putweapon(archer_name);
        arsenal->putweapon(knight_name);
        
        std::cout << "Weapon take" << std::endl;
        arsenal->takeweapon<Shovel>(peasant_name);
        arsenal->takeweapon<Bow>(archer_name);
        arsenal->takeweapon<Hammer>(knight_name);
        
        std::cout << "Put weapons back to arsenal" << std::endl;
        arsenal->putweapon(peasant_name);
        arsenal->putweapon(archer_name);
        arsenal->putweapon(knight_name);
        
        std::cout << "Leave people from stadium" << std::endl;
        peasant = arsenal->leave(peasant_name);
        archer = arsenal->leave(archer_name);
        knight = arsenal->leave(knight_name);
        
        std::cout << "Enter people to arsenal" << std::endl;
        barrack->enter(std::move(peasant));
        barrack->enter(std::move(archer));
        barrack->enter(std::move(knight));
    } catch(std::logic_error &s) {
        std::cerr << s.what() << std::endl;
    } catch(...) {
        std::cerr << "Oups" << std::endl;
    }
    return 0;
}
