#include "gtest/gtest.h"
#include "GameTests.hpp"

TEST_F(GameTests, Arsenal) {
    EXPECT_THROW(a.get_weapon(SWORD), std::logic_error);
    EXPECT_THROW(a.get_armor(CHAIN_ARMOUR), std::logic_error);
    
    a.put_weapon(std::unique_ptr<weapon>(new shovel));
    a.put_weapon(std::unique_ptr<weapon>(new sword));
    a.put_weapon(std::unique_ptr<weapon>(new hammer));
    a.put_weapon(std::unique_ptr<weapon>(new bow));
    
    a.put_armor(std::unique_ptr<armor>(new chain_armour));
    a.put_armor(std::unique_ptr<armor>(new lat));

    EXPECT_EQ(a.get_weapon(BOW)->get_type(), BOW);
    EXPECT_EQ(a.get_armor(LAT)->get_type(), LAT);
    
    EXPECT_THROW(a.get_weapon(BOW), std::logic_error);
    EXPECT_THROW(a.get_armor(LAT), std::logic_error);
}

TEST_F(GameTests, Storage) {
    EXPECT_THROW(b.get_unit("Mike"), std::logic_error);
    
    b.add_unit(std::unique_ptr<character>(new archer("Mike")));
    
    EXPECT_STREQ(b.get_unit("Mike")->get_name().c_str(), "Mike");
    
    EXPECT_THROW(b.get_unit("Mike"), std::logic_error);
}

TEST_F(GameTests, Attack) {
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

    s["Mike"].attack(s["Jack"]);
    EXPECT_NEAR(s["Jack"].get_health(), 8.04, 1e-3);
    
    s["Jack"].take_weapon(a.get_weapon(SWORD));
    s["Mike"].put_on_armor(a.get_armor(CHAIN_ARMOUR));
    
    s["Jack"].attack(s["Mike"]);
    EXPECT_NEAR(s["Mike"].get_health(), 4, 1e-3);
}
