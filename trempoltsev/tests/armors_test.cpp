#include "stdafx.h"

#include "../include/armors/chain_armor.h"
#include "../include/armors/plate_armor.h"
#include "../include/weapons/sword.h"

using namespace Arena;

class PlateArmorTest
    : public ::testing::Test
{
protected:
    PlateArmor armor;
};

void foo(Armor&& a)
{

}

template <class ArmorTraits, class WeaponTraits>
Points damage(const Details::ArmorImpl<ArmorTraits>& a, const Details::WeaponImpl<WeaponTraits>& w)
{
    return ArmorTraits::protection<WeaponTraits::DamageType>() - WeaponTraits::damage;
}

TEST_F(PlateArmorTest, spell_chars)
{
    PlateArmor a1;
    ChainArmor a2;
    Sword s;
    foo(std::move(a1));
    foo(std::move(a2));
    EXPECT_EQ(10, damage(a1, s));
    EXPECT_EQ(-20, damage(a2, s));
    EXPECT_EQ(4, sizeof(a1));
}
