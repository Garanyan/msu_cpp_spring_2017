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

TEST(SetupUniverse, Weapon) {
    std::unique_ptr<Sword> sword(new class Sword());
    std::unique_ptr<Hammer> hammer(new class Hammer());
    std::unique_ptr<Bow> bow(new class Bow());
    std::unique_ptr<Nothing> nothing(new class Nothing());
    std::unique_ptr<Shovel> shovel(new class Shovel());
    EXPECT_EQ(WeaponName::Sword, sword->getName());
    EXPECT_EQ(WeaponName::Hammer, hammer->getName());
    EXPECT_EQ(WeaponName::Bow, bow->getName());
    EXPECT_EQ(WeaponName::Nothing, nothing->getName());
    EXPECT_EQ(WeaponName::Shovel, shovel->getName());
    
    std::unique_ptr<Armor> torso(new class Torso());
    EXPECT_TRUE(sword->countBonus(*torso) > 0);
    EXPECT_TRUE(hammer->countBonus(*torso) > 0);
    EXPECT_TRUE(bow->countBonus(*torso) > 0);
    EXPECT_TRUE(nothing->countBonus(*torso) > 0);
    EXPECT_TRUE(shovel->countBonus(*torso) > 0);
    
    EXPECT_TRUE(sword->getPower() > 0);
    EXPECT_TRUE(hammer->getPower() > 0);
    EXPECT_TRUE(bow->getPower() > 0);
    EXPECT_TRUE(nothing->getPower() > 0);
    EXPECT_TRUE(shovel->getPower() > 0);
}

TEST(SetupUniverse, Human) {
    std::unique_ptr<Peasant> peasant(new class Peasant("Peasant"));
    std::unique_ptr<Knight> knight(new class Knight("Knight"));
    std::unique_ptr<Archer> archer(new class Archer("Archer"));
    std::unique_ptr<Archer> archerRandomName(new class Archer()); 
    std::unique_ptr<Archer> archerRandomName2(new class Archer()); 
    
    EXPECT_EQ(HumanProfession::Peasant, peasant->getProfession());
    EXPECT_EQ(HumanProfession::Archer, archer->getProfession());
    EXPECT_EQ(HumanProfession::Archer, archerRandomName->getProfession());
    EXPECT_EQ(HumanProfession::Archer, archerRandomName2->getProfession());
    EXPECT_EQ(HumanProfession::Knight, knight->getProfession());
    
    EXPECT_TRUE(peasant->getOffensePower() > 0);
    EXPECT_TRUE(archer->getOffensePower() > 0);
    EXPECT_TRUE(knight->getOffensePower() > 0);
    EXPECT_TRUE(archerRandomName->getOffensePower() > 0);
    EXPECT_TRUE(archerRandomName2->getOffensePower() > 0);
    
    EXPECT_TRUE(peasant->getDefensePower() > 0);
    EXPECT_TRUE(archer->getDefensePower() > 0);
    EXPECT_TRUE(knight->getDefensePower() > 0);
    EXPECT_TRUE(archerRandomName->getDefensePower() > 0);
    EXPECT_TRUE(archerRandomName2->getDefensePower() > 0);
    
    EXPECT_TRUE(peasant->life_ == peasant->getDefaultLife());
    EXPECT_TRUE(archer->life_ == archer->getDefaultLife());
    EXPECT_TRUE(knight->life_ == knight->getDefaultLife());
    EXPECT_TRUE(archerRandomName->life_ == archerRandomName->getDefaultLife());
    EXPECT_TRUE(archerRandomName2->life_ == archerRandomName2->getDefaultLife());
    
    EXPECT_TRUE(peasant->name_ == "Peasant");
    EXPECT_TRUE(archer->name_ == "Archer");
    EXPECT_TRUE(knight->name_ == "Knight");
    EXPECT_TRUE(archerRandomName->name_ != archerRandomName2->name_);
    
    EXPECT_TRUE(peasant->takeDamage(*archer) == 0);
    EXPECT_TRUE(peasant->takeDamage(*knight) > 0);
    EXPECT_TRUE(peasant->dealDamage(*knight) > 0);
    EXPECT_TRUE(peasant->dealDamage(*archer) > 0);
}

TEST(SetupUniverse, Location) {
    std::unique_ptr<Barrack> barrack(new class Barrack());
    std::unique_ptr<Stadium> stadium(new class Stadium());
    std::unique_ptr<Arsenal> arsenal(new class Arsenal());
    
    std::unique_ptr<Peasant> peasant(new class Peasant("Peasant"));
    std::unique_ptr<Knight> knight(new class Knight("Knight"));
    std::unique_ptr<Archer> archer(new class Archer("Archer"));
    
    EXPECT_FALSE(barrack->isInside("Peasant"));
    EXPECT_FALSE(barrack->isInside("Archer"));
    peasant->life_ = 1;
    EXPECT_TRUE(peasant->life_ == 1);
    barrack->enter(std::move(peasant));
    barrack->heal("Peasant");
    EXPECT_TRUE(barrack->isInside("Peasant"));
    EXPECT_FALSE(barrack->isInside("Archer"));
    auto newPeasant = barrack->leave("Peasant");
    EXPECT_TRUE(newPeasant->name_ == "Peasant");
    EXPECT_TRUE(newPeasant->life_ == newPeasant->getDefaultLife());
    EXPECT_FALSE(barrack->isInside("Peasant"));
    EXPECT_FALSE(barrack->isInside("Archer"));
    
    auto birthNamePeasant = barrack->birth<Peasant>("Peasant 2");
    auto birthNameArcher = barrack->birth<Archer>("Archer 2");
    auto birthNameKnight = barrack->birth<Knight>();
    EXPECT_TRUE(birthNamePeasant == "Peasant 2");
    EXPECT_TRUE(birthNameArcher == "Archer 2");
    newPeasant = barrack->leave(birthNamePeasant);
    auto newArcher = barrack->leave(birthNameArcher);
    auto newKnight = barrack->leave(birthNameKnight);
    EXPECT_TRUE(newPeasant->getProfession() == HumanProfession::Peasant);
    EXPECT_TRUE(newArcher->getProfession() == HumanProfession::Archer);
    
    arsenal->addArmor(ArmorName::Corslet);
    arsenal->addArmor(ArmorName::Chain);
    arsenal->addWeapon(WeaponName::Hammer);
    arsenal->addWeapon(WeaponName::Bow);
    arsenal->enter(std::move(newArcher));
    arsenal->enter(std::move(newKnight));
    arsenal->takeArmor<Chain>(birthNameArcher);
    arsenal->takeArmor<Corslet>(birthNameKnight);
    arsenal->takeWeapon<Bow>(birthNameArcher);
    arsenal->takeWeapon<Hammer>(birthNameKnight);
    newArcher = arsenal->leave(birthNameArcher);
    newKnight = arsenal->leave(birthNameKnight);
    EXPECT_TRUE(newArcher->weapon_->getName() == WeaponName::Bow);
    EXPECT_TRUE(newKnight->weapon_->getName() == WeaponName::Hammer);
    EXPECT_TRUE(newArcher->armor_->getName() == ArmorName::Chain);
    EXPECT_TRUE(newKnight->armor_->getName() == ArmorName::Corslet);
    
    arsenal->enter(std::move(newArcher));
    arsenal->enter(std::move(newKnight));
    arsenal->putArmor(birthNameArcher);
    arsenal->putArmor(birthNameKnight);
    arsenal->putWeapon(birthNameArcher);
    arsenal->putWeapon(birthNameKnight);
    newArcher = arsenal->leave(birthNameArcher);
    newKnight = arsenal->leave(birthNameKnight);
    EXPECT_TRUE(newArcher->weapon_->getName() == WeaponName::Nothing);
    EXPECT_TRUE(newKnight->weapon_->getName() == WeaponName::Nothing);
    EXPECT_TRUE(newArcher->armor_->getName() == ArmorName::Torso);
    EXPECT_TRUE(newKnight->armor_->getName() == ArmorName::Torso);
    
    stadium->enter(std::move(newArcher));
    stadium->enter(std::move(newKnight));
    EXPECT_TRUE(stadium->battle(birthNameKnight, birthNameArcher) == birthNameKnight);
}
