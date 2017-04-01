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
        std::string peasant_name = barrack->birth<Peasant>();
        std::string archer_name = barrack->birth<Archer>();
        std::string knight_name = barrack->birth<Knight>();
        std::cout << "Peasant: " << peasant_name << std::endl;
        std::cout << "Archer: " << archer_name << std::endl;
        std::cout << "Knight: " << knight_name << std::endl;
        
        arsenal->addarmor(ArmorName::Chain);
        arsenal->addarmor(ArmorName::Chain);
        arsenal->addarmor(ArmorName::Corslet);
        arsenal->addweapon(WeaponName::Bow);
        arsenal->addweapon(WeaponName::Shovel);
        arsenal->addweapon(WeaponName::Hammer);
        arsenal->addweapon(WeaponName::Sword);
        
        std::unique_ptr<Peasant> peasant = barrack->leave<Peasant>(peasant_name);
        std::unique_ptr<Archer> archer = barrack->leave<Archer>(archer_name);
        std::unique_ptr<Knight> knight = barrack->leave<Knight>(knight_name);
        
        arsenal->enter(std::move(peasant));
        arsenal->enter(std::move(archer));
        arsenal->enter(std::move(knight));
        
        arsenal->takeweapon<Shovel>(peasant_name);
        arsenal->takeweapon<Bow>(archer_name);
        arsenal->takeweapon<Hammer>(knight_name);
        
        arsenal->takearmor<Chain>(peasant_name);
        arsenal->takearmor<Chain>(archer_name);
        arsenal->takearmor<Corslet>(knight_name);
        
        peasant = arsenal->leave<Peasant>(peasant_name);
        archer = arsenal->leave<Archer>(archer_name);
        knight = arsenal->leave<Knight>(knight_name);
        
        stadium->enter(std::move(peasant));
        stadium->enter(std::move(archer));
        stadium->enter(std::move(knight));
        
        std::string winner = stadium->battle(peasant_name, archer_name);
        std::cout << "Winner: " << winner << std::endl;
        stadium->heal(peasant_name);
        stadium->heal(archer_name);
        
        winner = stadium->battle(archer_name, knight_name);
        std::cout << "Winner: " << winner << std::endl;
        stadium->heal(knight_name);
        stadium->heal(archer_name);
        
        winner = stadium->battle(peasant_name, archer_name);
        std::cout << "Winner: " << winner << std::endl;
        stadium->heal(peasant_name);
        stadium->heal(archer_name);
        
        peasant = stadium->leave<Peasant>(peasant_name);
        archer = stadium->leave<Archer>(archer_name);
        knight = stadium->leave<Knight>(knight_name);
        
        arsenal->enter(std::move(peasant));
        arsenal->enter(std::move(archer));
        arsenal->enter(std::move(knight));
        
        arsenal->putweapon(peasant_name);
        arsenal->putweapon(archer_name);
        arsenal->putweapon(knight_name);
        
        arsenal->takeweapon<Shovel>(peasant_name);
        arsenal->takeweapon<Bow>(archer_name);
        arsenal->takeweapon<Hammer>(knight_name);
        
        arsenal->putweapon(peasant_name);
        arsenal->putweapon(archer_name);
        arsenal->putweapon(knight_name);
        
        peasant = arsenal->leave<Peasant>(peasant_name);
        archer = arsenal->leave<Archer>(archer_name);
        knight = arsenal->leave<Knight>(knight_name);
        
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
