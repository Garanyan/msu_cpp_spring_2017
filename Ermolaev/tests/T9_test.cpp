#include "stdafx.h"
#include "../src/T9.h"


class T9TestingUnit : public ::testing::Test
{
public:
	T9 t;
};

TEST_F(T9TestingUnit, single_characters)
{
	EXPECT_STREQ("0",   t.translate(" ").c_str());
    
	EXPECT_STREQ("2",   t.translate("a").c_str());
	EXPECT_STREQ("22",  t.translate("b").c_str());
	EXPECT_STREQ("222", t.translate("c").c_str());

	EXPECT_STREQ("3",   t.translate("d").c_str());
	EXPECT_STREQ("33",  t.translate("e").c_str());
	EXPECT_STREQ("333", t.translate("f").c_str());

	EXPECT_STREQ("4",   t.translate("g").c_str());
	EXPECT_STREQ("44",  t.translate("h").c_str());
	EXPECT_STREQ("444", t.translate("i").c_str());

	EXPECT_STREQ("5",   t.translate("j").c_str());
	EXPECT_STREQ("55",  t.translate("k").c_str());
	EXPECT_STREQ("555", t.translate("l").c_str());

	EXPECT_STREQ("6",   t.translate("m").c_str());
	EXPECT_STREQ("66",  t.translate("n").c_str());
	EXPECT_STREQ("666", t.translate("o").c_str());

	EXPECT_STREQ("7",   t.translate("p").c_str());
	EXPECT_STREQ("77",  t.translate("q").c_str());
	EXPECT_STREQ("777", t.translate("r").c_str());
	EXPECT_STREQ("7777",t.translate("s").c_str());

	EXPECT_STREQ("8",   t.translate("t").c_str());
	EXPECT_STREQ("88",  t.translate("u").c_str());
	EXPECT_STREQ("888", t.translate("v").c_str());

	EXPECT_STREQ("9",   t.translate("w").c_str());
	EXPECT_STREQ("99",  t.translate("x").c_str());
	EXPECT_STREQ("999", t.translate("y").c_str());
	EXPECT_STREQ("9999",t.translate("z").c_str());
}

TEST_F(T9TestingUnit, words_and_phrases)
{
	EXPECT_STREQ("44 444",    t.translate("hi").c_str());
	EXPECT_STREQ("999337777", t.translate("yes").c_str());
	EXPECT_STREQ("333666 6660 022 2777",       t.translate("foo  bar").c_str());
	EXPECT_STREQ("4433555 555666096667775553", t.translate("hello world").c_str());

    EXPECT_STREQ("0 0", t.translate("  ").c_str());
    EXPECT_STREQ("0 04433555 555666096667775553",    t.translate("  hello world").c_str());
    EXPECT_STREQ("4433555 5556660966677755530 0",    t.translate("hello world  ").c_str());
    EXPECT_STREQ("04433555 5556660 0 0966677755530", t.translate(" hello   world ").c_str());

    EXPECT_STREQ("44_",    t.translate("h1").c_str());
	EXPECT_STREQ("999_7777", t.translate("y8s").c_str());
    EXPECT_STREQ("999_0", t.translate("y1 ").c_str());
}

TEST_F(T9TestingUnit, errors_testing)
{
    EXPECT_THROW(t.translate(""),    std::invalid_argument);
}
