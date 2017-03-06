#include "../src/t9sol.h"
#include "stdafx.h"



TEST(T9Test, Cases) {
    ASSERT_STREQ("44 444", t9solve("hi").c_str());

    ASSERT_STREQ("999337777", t9solve("yes").c_str());

    ASSERT_STREQ("333666 6660 022 2777", t9solve("foo  bar").c_str());

    ASSERT_STREQ("4433555 555666096667775553", t9solve("hello world").c_str());
}

TEST(T9Test, Errors)
{
	ASSERT_STREQ("input is empty", t9solve("").c_str());
	ASSERT_STREQ("invalid input", t9solve("1").c_str());
	ASSERT_STREQ("invalid input", t9solve("a1").c_str());
	ASSERT_STREQ("invalid input", t9solve("Hi").c_str());
	ASSERT_STREQ("invalid input", t9solve("hello World").c_str());
	ASSERT_STREQ("invalid input", t9solve("hello 123").c_str());
}
