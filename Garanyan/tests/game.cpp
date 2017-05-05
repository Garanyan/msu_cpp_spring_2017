#include "gtest/gtest.h"
#include "../TheMedievalPeriodFights/include/armor.h"
#include "../TheMedievalPeriodFights/include/weapon.h"

class gameTest
	: public ::testing::Test
{
protected:
	FullPlateArmor a;
	LightSuit  b;
	Naked c;
	Sword s;
	Hammer h;
	Bow bow;
	Fist f;
};

TEST_F(gameTest, armorTest)
{
    
    EXPECT_EQ( 10,a.getProtection(DamageType::BOW) );
    EXPECT_EQ( 0 ,a.getProtection(DamageType::FIST) );
    EXPECT_EQ( 10 ,a.getProtection(DamageType::HUMMER) );
    EXPECT_EQ( 35,a.getProtection(DamageType::SWORD) );

	EXPECT_EQ(20, b.getProtection(DamageType::BOW));
	EXPECT_EQ(5, b.getProtection(DamageType::FIST));
	EXPECT_EQ(33, b.getProtection(DamageType::HUMMER));
	EXPECT_EQ(23, b.getProtection(DamageType::SWORD));

	EXPECT_EQ(40, c.getProtection(DamageType::BOW));
	EXPECT_EQ(20, c.getProtection(DamageType::FIST));
	EXPECT_EQ(70, c.getProtection(DamageType::HUMMER));
	EXPECT_EQ(50, c.getProtection(DamageType::SWORD));
	
    
}

TEST_F(gameTest, weaponTest)
{
	
	EXPECT_EQ(DamageType::SWORD, s.getDamageType());
	EXPECT_EQ(DamageType::BOW, bow.getDamageType());
	EXPECT_EQ(DamageType::FIST, f.getDamageType());
	EXPECT_EQ(DamageType::HUMMER, h.getDamageType());
}
