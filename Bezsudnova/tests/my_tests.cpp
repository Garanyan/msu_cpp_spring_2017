#include "stdafx.h"

#include "../src/trans.h"


TEST(translate, Test1) {
	EXPECT_STREQ("44 444", translate("hi").c_str());
}
TEST(translate, Test2) {
	EXPECT_STREQ("999337777", translate("yes").c_str());
}
TEST(translate, Test3) {
	EXPECT_STREQ("333666 6660 022 2777", translate("foo  bar").c_str());
}
TEST(translate, Test4) {
	EXPECT_STREQ("4433555 555666096667775553", translate("hello world").c_str());
}
TEST(translate, TestError0) {
	EXPECT_STREQ("ERROR", translate("1").c_str());
}
