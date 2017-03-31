#include "stdafx.h"

#include "../include/armors/chain_armor.h"
#include "../include/armors/plate_armor.h"

#include "../include/units/archer.h"
#include "../include/units/knight.h"
#include "../include/units/peasant.h"

#include "../include/weapons/bow.h"
#include "../include/weapons/fists.h"
#include "../include/weapons/hammer.h"
#include "../include/weapons/shovel.h"
#include "../include/weapons/sword.h"

using namespace Arena;

TEST(UnitsTest, TestAccessors)
{
    EXPECT_EQ(0.6, (getArmorSkill<Details::PeasantTraits, Details::ChainArmorTraits>()));
    EXPECT_EQ(0.2, (getArmorSkill<Details::PeasantTraits, Details::PlateArmorTraits>()));
    EXPECT_EQ(2.5, (getArmorSkill<Details::PeasantTraits, Details::WithoutArmorTraits>()));

    EXPECT_EQ(0.5, (getWeaponSkill<Details::PeasantTraits, Details::BowTraits>()));
    EXPECT_EQ(3.0, (getWeaponSkill<Details::PeasantTraits, Details::FistsTraits>()));
    EXPECT_EQ(1.5, (getWeaponSkill<Details::PeasantTraits, Details::HammerTraits>()));
    EXPECT_EQ(1.5, (getWeaponSkill<Details::PeasantTraits, Details::ShovelTraits>()));
    EXPECT_EQ(0.8, (getWeaponSkill<Details::PeasantTraits, Details::SwordTraits>()));
}

TEST(UnitsTest, TestArcher)
{
    Archer archer("Tom");
}

TEST(UnitsTest, TestKnight)
{
    Knight knight("Jack");
}

TEST(UnitsTest, TestPeasant)
{
    Peasant peasant("Bob");
}
