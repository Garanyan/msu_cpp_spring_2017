#include "../src/libt9.h"
#include "stdafx.h"

TEST(SheviakovTest, Test1) {
    ASSERT_EQ("44 444", convert("hi"));
}
TEST(SheviakovTest, Test2) {
    ASSERT_EQ("999337777", convert("yes"));
}
TEST(SheviakovTest, Test3) {
    ASSERT_EQ("333666 6660 022 2777", convert("foo  bar"));
}
TEST(SheviakovTest, Test4) {
    ASSERT_EQ("4433555 555666096667775553", convert("hello world"));
}
