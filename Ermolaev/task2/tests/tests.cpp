#include "stdafx.h"
#include "../include/Person.h"
#include "../include/Armor.h"
#include "../include/Weapon.h"
#include "../include/Arena.h"
#include "../include/Barack.h"
#include "../include/Arsenal.h"

TEST(CreateUnitsAndWeapons, PleaseDoNotFall) {

    // Create
    std::unique_ptr<WithoutArmor> withoutArmor(new WithoutArmor());
    std::unique_ptr<Chains>  chains(new Chains());
    std::unique_ptr<Plates> plates(new Plates());

    std::unique_ptr<Fists> fists(new Fists());
    std::unique_ptr<Bow> bow(new Bow());
    std::unique_ptr<Sword> sword(new Sword());

    std::unique_ptr<Peasant> peasant(new Peasant("p"));
    std::unique_ptr<Archer> archer(new Archer("a"));
    std::unique_ptr<Knight> knight(new Knight("k"));


    // Take and Wear
    peasant->wearArmor(std::move(chains));
    peasant->takeWeapon(std::move(bow));

    archer->wearArmor(std::move(plates));
    archer->takeWeapon(std::move(sword));

    knight->wearArmor(std::move(withoutArmor));
    knight->takeWeapon(std::move(fists));

    testing::internal::CaptureStdout();
    peasant->printStats();
    std::string output1 = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    archer->printStats();
    std::string output2 = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    knight->printStats();
    std::string output3 = testing::internal::GetCapturedStdout();

    EXPECT_STREQ("Peasant p health=50 Bow dur=1 Chains dur=60\n", output1.c_str());
    EXPECT_STREQ("Archer a health=80 Sword dur=1 Plates dur=100\n", output2.c_str());
    EXPECT_STREQ("Knight k health=100 Fists dur=-1 WithoutArmor dur=-1\n", output3.c_str());
}


TEST(CreateBuldingsAndFight, PleaseDoNotFall) {
    auto arena = new Arena();
    auto barack = new Barack();
    auto arsenal = new Arsenal();

    // Barack
    barack->addRandomPerson("hey");
    barack->createPerson<Archer>("hoy");
    EXPECT_STREQ(barack->callPerson("hoy")->getJob().c_str(), "Archer");

    // Arsenal
    std::unique_ptr<Chains> chains(new Chains());
    std::unique_ptr<Plates> plates(new Plates());

    std::unique_ptr<Bow> bow(new Bow());
    std::unique_ptr<Sword> sword(new Sword());

    arsenal->putWeapon(std::move(bow));
    arsenal->addRandomWeapon();
    arsenal->putWeapon(std::move(sword));

    arsenal->putArmor(std::move(chains));
    arsenal->addRandomArmor();
    arsenal->putArmor(std::move(plates));

    std::unique_ptr<Peasant> peasant(new Peasant("p"));
    peasant->wearArmor(std::move(arsenal->getArmor()));
    peasant->takeWeapon(std::move(arsenal->getWeapon()));

    testing::internal::CaptureStdout();
    peasant->printStats();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_STREQ("Peasant p health=50 Sword dur=1 Plates dur=100\n", output.c_str());

    // Arena
    barack->addRandomPerson("1");
    barack->addRandomPerson("2");

    auto unit1 = barack->callRandPerson();
    auto unit2 = barack->callRandPerson();

    unit1->takeWeapon(arsenal->getWeapon());
    unit1->wearArmor(arsenal->getArmor());
    unit2->takeWeapon(arsenal->getWeapon());
    unit2->wearArmor(arsenal->getArmor());

    arena->addToFighters(std::move(unit1));
    arena->addToFighters(std::move(unit2));

    arena->fightsNet();
}



