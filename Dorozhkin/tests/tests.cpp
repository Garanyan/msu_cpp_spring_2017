#include "stdafx.h"
#include "../include/main.h"

TEST(DorozhkinTest, Test1) {
    EXPECT_STREQ("1 1 1", dile("aaa").c_str());
}
