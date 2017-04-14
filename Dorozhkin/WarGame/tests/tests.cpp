#include "stdafx.h"
#include "../include/Human.h"
#include "../include/Armor.h"
#include "../include/Weapon.h"
#include "../include/Location.h"

TEST(SetupUniverse, Armor) {
    std::unique_ptr<Torso> torso(new class Torso());
    std::unique_ptr<Chain> chain(new class Chain());
    std::unique_ptr<Corslet> corslet(new class Corslet());
    EXPECT_EQ(ArmorName::Torso, torso->getName());
    EXPECT_EQ(ArmorName::Chain, chain->getName());
    EXPECT_EQ(ArmorName::Corslet, corslet->getName());
    
    std::unique_ptr<Weapon> hammer(new class Hammer());
    EXPECT_TRUE(torso->countBonus(*hammer) < 0);
    EXPECT_TRUE(chain->countBonus(*hammer) < 0);
    EXPECT_TRUE(corslet->countBonus(*hammer) == 0);
    
    EXPECT_TRUE(torso->getPower() == 0);
    EXPECT_TRUE(chain->getPower() > 0);
    EXPECT_TRUE(corslet->getPower() > 0);
}


// static constexpr ArmorName name = ArmorName::Armor;
// int getPower() const; 

TEST(WordTestGroup, ComplexTests) {
}

// 
// std::unique_ptr<Barrack> barrack(new class Barrack());
// std::unique_ptr<Stadium> stadium(new class Stadium());
// std::unique_ptr<Arsenal> arsenal(new class Arsenal());
// std::string peasant_name = barrack->birth<Peasant>("Cowboy");
// std::string archer_name = barrack->birth<Archer>("Legolas");
// std::string knight_name = barrack->birth<Knight>("Uter");
// std::cout << "Peasant: " << peasant_name << std::endl;
// std::cout << "Archer: " << archer_name << std::endl;
// std::cout << "Knight: " << knight_name << std::endl;
// 
// std::cout << "Adding weapons and armors to arsenal" << std::endl;
// arsenal->addArmor(ArmorName::Chain);
// arsenal->addArmor(ArmorName::Chain);
// arsenal->addArmor(ArmorName::Corslet);
// arsenal->addWeapon(WeaponName::Bow);
// arsenal->addWeapon(WeaponName::Shovel);
// arsenal->addWeapon(WeaponName::Hammer);
// arsenal->addWeapon(WeaponName::Sword);
// 
// std::cout << "Leave people from barrack" << std::endl;
// std::unique_ptr<Human> peasant = barrack->leave(peasant_name);
// std::unique_ptr<Human> archer = barrack->leave(archer_name);
// std::unique_ptr<Human> knight = barrack->leave(knight_name);
// 
// std::cout << "Enter people to arsenal" << std::endl;
// arsenal->enter(std::move(peasant));
// arsenal->enter(std::move(archer));
// arsenal->enter(std::move(knight));
// 
// std::cout << "Weapon take" << std::endl;
// arsenal->takeWeapon<Shovel>(peasant_name);
// arsenal->takeWeapon<Bow>(archer_name);
// arsenal->takeWeapon<Hammer>(knight_name);
// 
// std::cout << "Armor take" << std::endl;
// arsenal->takeArmor<Chain>(peasant_name);
// arsenal->takeArmor<Chain>(archer_name);
// arsenal->takeArmor<Corslet>(knight_name);
// 
// std::cout << "Leave people from arsenal" << std::endl;
// peasant = arsenal->leave(peasant_name);
// archer = arsenal->leave(archer_name);
// knight = arsenal->leave(knight_name);
// 
// std::cout << "Enter people to stadium" << std::endl;
// stadium->enter(std::move(peasant));
// stadium->enter(std::move(archer));
// stadium->enter(std::move(knight));
// 
// std::cout << "Battle 1" << std::endl;
// std::string winner = stadium->battle(peasant_name, archer_name);
// std::cout << "Winner: " << winner << std::endl;
// stadium->heal(peasant_name);
// stadium->heal(archer_name);
// 
// std::cout << "Battle 2" << std::endl;
// winner = stadium->battle(archer_name, knight_name);
// std::cout << "Winner: " << winner << std::endl;
// stadium->heal(knight_name);
// stadium->heal(archer_name);
// 
// std::cout << "Battle 3" << std::endl;
// winner = stadium->battle(peasant_name, archer_name);
// std::cout << "Winner: " << winner << std::endl;
// stadium->heal(peasant_name);
// stadium->heal(archer_name);
// 
// std::cout << "Leave people from stadium" << std::endl;
// peasant = stadium->leave(peasant_name);
// archer = stadium->leave(archer_name);
// knight = stadium->leave(knight_name);
// 
// std::cout << "Enter people to arsenal" << std::endl;
// arsenal->enter(std::move(peasant));
// arsenal->enter(std::move(archer));
// arsenal->enter(std::move(knight));
// 
// std::cout << "Put weapons back to arsenal" << std::endl;
// arsenal->putWeapon(peasant_name);
// arsenal->putWeapon(archer_name);
// arsenal->putWeapon(knight_name);
// 
// std::cout << "Weapon take" << std::endl;
// arsenal->takeWeapon<Shovel>(peasant_name);
// arsenal->takeWeapon<Bow>(archer_name);
// arsenal->takeWeapon<Hammer>(knight_name);
// 
// std::cout << "Put weapons back to arsenal" << std::endl;
// arsenal->putWeapon(peasant_name);
// arsenal->putWeapon(archer_name);
// arsenal->putWeapon(knight_name);
// 
// std::cout << "Leave people from stadium" << std::endl;
// peasant = arsenal->leave(peasant_name);
// archer = arsenal->leave(archer_name);
// knight = arsenal->leave(knight_name);
// 
// std::cout << "Enter people to arsenal" << std::endl;
// barrack->enter(std::move(peasant));
// barrack->enter(std::move(archer));
// barrack->enter(std::move(knight));
