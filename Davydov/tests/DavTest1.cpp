#include "stdafx.h"

TEST(transform, Test0) {
	ASSERT_EQ("55544433333 444777 2 7244466", t9solve("life is a pain"));
}
TEST(transform, Test1) {
	ASSERT_EQ("44 444", t9solve("hi"));
}
TEST(transform, Test2) {
	ASSERT_EQ("999337777", t9solve("yes"));
}
TEST(transform, Test3) {
	ASSERT_EQ("333666 6660 022 2777", t9solve("foo  bar"));
}
TEST(transform, Test4) {
	ASSERT_EQ("4433555 555666096667775553", t9solve("hello world"));
}
