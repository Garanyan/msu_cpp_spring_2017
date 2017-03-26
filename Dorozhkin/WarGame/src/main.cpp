#pragma once 
#include "../include/Armor.h"
#include "../include/Weapon.h"
#include "../include/Location.h"
#include "../include/Human.h"
#include "../include/include.h"

int main(int argc, char const *argv[]) {
    Barrack barrack{};
    Stadium stadium{};
    Arsenal arsenal{};
    std::string peasant_name = barrack.birth<Peasant>();
    std::string archer_name = barrack.birth<Archer>();
    std::string knight_name = barrack.birth<Knight>();
    std::cout << "Peasant: " << peasant_name << std::endl;
    std::cout << "Archer: " << archer_name << std::endl;
    std::cout << "Knight: " << knight_name << std::endl;
    
    arsenal.addarmor<Chain>();
    arsenal.addarmor<Chain>();
    arsenal.addarmor<Corslet>();
    arsenal.addweapon<Bow>();
    arsenal.addweapon<Shovel>();
    arsenal.addweapon<Hammer>();
    arsenal.addweapon<Sword>();
    
    Peasant peasant = barrack.leave<Peasant>(peasant_name);
    Archer archer = barrack.leave<Archer>(archer_name);
    Knight knight = barrack.leave<Knight>(knight_name);
        
    arsenal.enter<Peasant>(std::move(peasant));
    arsenal.enter<Archer>(std::move(archer));
    arsenal.enter<Knight>(std::move(knight));
    
    arsenal.takeweapon<Shovel>(peasant_name);
    arsenal.takeweapon<Bow>(archer_name);
    arsenal.takeweapon<Hammer>(knight_name);
    
    arsenal.takearmor<Chain>(peasant_name);
    arsenal.takearmor<Chain>(archer_name);
    arsenal.takearmor<Corslet>(knight_name);
    
    peasant = arsenal.leave<Peasant>(peasant_name);
    archer = arsenal.leave<Archer>(archer_name);
    knight = arsenal.leave<Knight>(knight_name);
    
    stadium.enter<Peasant>(std::move(peasant));
    stadium.enter<Archer>(std::move(archer));
    stadium.enter<Knight>(std::move(knight));
    
    std::string winner = stadium.battle(peasant_name, archer_name);
    std::cout << "Winner: " << winner << std::endl;
    stadium.heal(peasant_name);
    stadium.heal(archer_name);
    
    winner = stadium.battle(archer_name, knight_name);
    std::cout << "Winner: " << winner << std::endl;
    stadium.heal(knight_name);
    stadium.heal(archer_name);
    
    winner = stadium.battle(peasant_name, archer_name);
    std::cout << "Winner: " << winner << std::endl;
    stadium.heal(peasant_name);
    stadium.heal(archer_name);
    
    peasant = stadium.leave<Peasant>(peasant_name);
    archer = stadium.leave<Archer>(archer_name);
    knight = stadium.leave<Knight>(knight_name);
    
    arsenal.enter<Peasant>(std::move(peasant));
    arsenal.enter<Archer>(std::move(archer));
    arsenal.enter<Knight>(std::move(knight));
    
    arsenal.putweapon<Shovel>(peasant_name);
    arsenal.putweapon<Bow>(archer_name);
    arsenal.putweapon<Knight>(knight_name);

    arsenal.takeweapon<Shovel>(peasant_name);
    arsenal.takeweapon<Bow>(archer_name);
    arsenal.takeweapon<Hammer>(knight_name);

    arsenal.putweapon<Shovel>(peasant_name);
    arsenal.putweapon<Bow>(archer_name);
    arsenal.putweapon<Hammer>(knight_name);
    
    peasant = arsenal.leave<Peasant>(peasant_name);
    archer = arsenal.leave<Archer>(archer_name);
    knight = arsenal.leave<Knight>(knight_name);
    
    barrack.enter<Peasant>(std::move(peasant));
    barrack.enter<Archer>(std::move(archer));
    barrack.enter<Knight>(std::move(knight));

    return 0;
}
