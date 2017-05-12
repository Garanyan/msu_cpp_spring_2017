#include "army_factory.hpp"

army_factory::army_factory(std::unique_ptr<unitFactory> uf) {
    ufp = std::move(uf);
}

std::unique_ptr<army> army_factory::getArmy(int n) {
    std::unique_ptr<army> ap(new army);
    
    for (int i=0; i<n; ++i) {
        ap -> add_unit(ufp -> getUnit());
    }
    
    return ap;
}

roman_army_factory::roman_army_factory(): army_factory(std::unique_ptr<unitFactory> (new romanUnitFactory)) {};

barbarian_army_factory::barbarian_army_factory(): army_factory(std::unique_ptr<unitFactory> (new barbarianUnitFactory)) {};
