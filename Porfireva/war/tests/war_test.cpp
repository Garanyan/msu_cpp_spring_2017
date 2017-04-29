#include "stdafx.h"

#include "../include/armor.h"

TEST(T9_war, test_armor)
{
    Corslet c;
    EXPECT_EQ(c.getTestValue(), 5);
}
