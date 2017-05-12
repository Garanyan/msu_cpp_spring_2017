#include <iostream>
#include "army_factory.hpp"

int main() {
    roman_army_factory raf;
    barbarian_army_factory baf;
    
    auto roman_army = raf.getArmy(10);
    auto barbarian_army = baf.getArmy(10);
    
    std::cout << "!!! ROMAN ARMY:" << std::endl;
    roman_army -> save(std::cout);
    
    std::cout << "!!! BARBARIAN ARMY:" << std::endl;
    barbarian_army -> save(std::cout);
    
    return 0;
}
