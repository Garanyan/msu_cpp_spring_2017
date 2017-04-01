#include <iostream>
#include <memory>
#include "character.hpp"
#include "storage.hpp"
#include "arsenal.hpp"

int main() {
    arsenal a;
    
    barracks b;
    stadium s;
    
    a.put_weapon(std::unique_ptr<weapon>(new shovel));
    a.put_weapon(std::unique_ptr<weapon>(new sword));
    a.put_weapon(std::unique_ptr<weapon>(new hammer));
    a.put_weapon(std::unique_ptr<weapon>(new bow));
    
    a.put_armor(std::unique_ptr<armor>(new chain_armour));
    a.put_armor(std::unique_ptr<armor>(new lat));
    
    b.add_unit(std::unique_ptr<character>(new peasant("Bob")));
    b.add_unit(std::unique_ptr<character>(new archer("Mike")));
    b.add_unit(std::unique_ptr<character>(new knight("Jack")));
    
    s.add_unit(b.get_unit("Mike"));
    s.add_unit(b.get_unit("Jack"));
    
    s["Mike"].attak(s["Jack"]);
    std::cout << s["Jack"].get_health() << std::endl;
    
    s["Jack"].take_weapon(a.get_weapon(SWORD));
    s["Mike"].put_on_armor(a.get_armor(CHAIN_ARMOUR));
    
    s["Jack"].attak(s["Mike"]);
    std::cout << s["Mike"].get_health() << std::endl;
    
    return 0;
}
