#include "../src/t9sol.h"
#include "stdafx.h"

TEST(T9Test, Test1) {
    ASSERT_EQ("44 444", t9solve("hi"));
}
TEST(T9Test, Test2) {
    ASSERT_EQ("999337777", t9solve("yes"));
}
TEST(T9Test, Test3) {
    ASSERT_EQ("333666 6660 022 2777", t9solve("foo  bar"));
}
TEST(T9Test, Test4) {
    ASSERT_EQ("4433555 555666096667775553", t9solve("hello world"));
}

