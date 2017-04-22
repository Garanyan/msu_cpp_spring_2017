#include "Armor.h"
#include "Weapon.h"
#include "Person.h"

#include "Arsenal.h"
#include "Barack.h"
#include "Arena.h"

#include "stdafx.h"
#include "utils.h"

int main(){
    Arsenal arsenal;
    Barack barack;
    Arena arena;

    for (int i = 0; i < 4; ++i) {
        arsenal.addRandomArmor();
        arsenal.addRandomWeapon();
    }

    for (int j = 0; j < 2; ++j) {
        std::string name = "test" + std::to_string(j);
        barack.addRandomPerson(name);
    }

    auto winner = arena.fightsNet();
    std::cout << "winner: ";
    winner->printStats();

    return 0;
}



