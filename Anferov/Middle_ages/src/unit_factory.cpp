#include <random>
#include <chrono>
#include <string>
#include "unit_factory.hpp"

std::unique_ptr<character> romanUnitFactory::getUnit() {
    static unsigned seed = unsigned(std::chrono::system_clock::now().time_since_epoch().count());
    static std::default_random_engine generator (seed);
    static std::uniform_int_distribution<int> distribution(0,2);
    static int counter = 0;
    
    switch (distribution(generator)) {
        case 0:
        {
            auto u = std::unique_ptr<character>(new archer("RomanUnit"+std::to_string(counter++)));
            u -> put_on_armor(std::unique_ptr<armor>(new chain_armour));
            u -> take_weapon(std::unique_ptr<weapon>(new bow));
            return u;
        }
            
        case 1:
        {
            auto u = std::unique_ptr<character>(new knight("RomanUnit"+std::to_string(counter++)));
            u -> put_on_armor(std::unique_ptr<armor>(new lat));
            u -> take_weapon(std::unique_ptr<weapon>(new sword));
            return u;
        }

        case 2:
        {
            auto u = std::unique_ptr<character>(new horseman("RomanUnit"+std::to_string(counter++)));
            u -> put_on_armor(std::unique_ptr<armor>(new lat));
            u -> take_weapon(std::unique_ptr<weapon>(new sword));
            return u;
        }

        default:
            throw std::logic_error("std::random fail!");
    }
    
    
}

std::unique_ptr<character> barbarianUnitFactory::getUnit() {
    static unsigned seed = unsigned(std::chrono::system_clock::now().time_since_epoch().count());
    static std::default_random_engine generator (seed);
    static std::uniform_int_distribution<int> distribution(0,1);
    static int counter = 0;
    
    switch (distribution(generator)) {
        case 0:
        {
            auto u = std::unique_ptr<character>(new archer("BarbarianUnit"+std::to_string(counter++)));
            u -> put_on_armor(std::unique_ptr<armor>(new chain_armour));
            u -> take_weapon(std::unique_ptr<weapon>(new bow));
            return u;
        }
            
        case 1:
        {
            auto u = std::unique_ptr<character>(new knight("BarbarianUnit"+std::to_string(counter++)));
            u -> put_on_armor(std::unique_ptr<armor>(new lat));
            u -> take_weapon(std::unique_ptr<weapon>(new sword));
            return u;
        }

        default:
            throw std::logic_error("std::random fail!");
    }
}
