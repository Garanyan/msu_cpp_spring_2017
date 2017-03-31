#include "stdafx.h"

#include "../include/armors/chain_armor.h"
#include "../include/armors/plate_armor.h"

#include "../include/weapons/bow.h"
#include "../include/weapons/fists.h"
#include "../include/weapons/hammer.h"
#include "../include/weapons/shovel.h"
#include "../include/weapons/sword.h"

using namespace Arena;

TEST(ArmorsTest, TestAccessors)
{
    EXPECT_EQ(30, (getProtection<Details::ChainArmorTraits, Details::BowTraits>()));
    EXPECT_EQ(10, (getProtection<Details::ChainArmorTraits, Details::FistsTraits>()));
    EXPECT_EQ(10, (getProtection<Details::ChainArmorTraits, Details::HammerTraits>()));
    EXPECT_EQ(10, (getProtection<Details::ChainArmorTraits, Details::ShovelTraits>()));
    EXPECT_EQ(50, (getProtection<Details::ChainArmorTraits, Details::SwordTraits>()));

    EXPECT_EQ(60, (getProtection<Details::PlateArmorTraits, Details::BowTraits>()));
    EXPECT_EQ(40, (getProtection<Details::PlateArmorTraits, Details::FistsTraits>()));
    EXPECT_EQ(40, (getProtection<Details::PlateArmorTraits, Details::HammerTraits>()));
    EXPECT_EQ(40, (getProtection<Details::PlateArmorTraits, Details::ShovelTraits>()));
    EXPECT_EQ(80, (getProtection<Details::PlateArmorTraits, Details::SwordTraits>()));
}

TEST(ArmorsTest, TestChain)
{
    ChainArmor chain;
}

TEST(ArmorsTest, TestPlate)
{
    PlateArmor plate;
}
