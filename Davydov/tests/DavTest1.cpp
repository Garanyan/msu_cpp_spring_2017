#include "stdafx.h"
#include "../Davydov/src/t9transform.h"

TEST(transform, Test0) {
	EXPECT_STREQ("55544433333 444777 2 7244466", transform("life is a pain").c_str());
}
TEST(transform, Test1) {
	EXPECT_STREQ("44 444", transform("hi").c_str());
}
TEST(transform, Test2) {
	EXPECT_STREQ("999337777", transform("yes").c_str());
}
TEST(transform, Test3) {
	EXPECT_STREQ("333666 6660 022 2777", transform("foo  bar").c_str());
}
TEST(transform, Test4) {
	EXPECT_STREQ("4433555 555666096667775553", transform("hello world").c_str());
}
TEST(transform, TestError0) {
	EXPECT_STREQ("ERROR", transform("abyr01abyr").c_str());
}