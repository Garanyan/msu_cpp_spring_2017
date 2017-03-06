#include "stdafx.h"

#include "../src/Converter.h"

class Converter_test
	: public ::testing::Test
{
protected:
	Converter converter;
};

TEST_F(Converter_test, check_chars)
{
	EXPECT_STREQ("2", converter.solve("a").c_str());
	EXPECT_STREQ("22", converter.solve("b").c_str());
	EXPECT_STREQ("222", converter.solve("c").c_str());

	EXPECT_STREQ("3", converter.solve("d").c_str());
	EXPECT_STREQ("33", converter.solve("e").c_str());
	EXPECT_STREQ("333", converter.solve("f").c_str());

	EXPECT_STREQ("4", converter.solve("g").c_str());
	EXPECT_STREQ("44", converter.solve("h").c_str());
	EXPECT_STREQ("444", converter.solve("i").c_str());

	EXPECT_STREQ("5", converter.solve("j").c_str());
	EXPECT_STREQ("55", converter.solve("k").c_str());
	EXPECT_STREQ("555", converter.solve("l").c_str());

	EXPECT_STREQ("6", converter.solve("m").c_str());
	EXPECT_STREQ("66", converter.solve("n").c_str());
	EXPECT_STREQ("666", converter.solve("o").c_str());

	EXPECT_STREQ("7", converter.solve("p").c_str());
	EXPECT_STREQ("77", converter.solve("q").c_str());
	EXPECT_STREQ("777", converter.solve("r").c_str());
	EXPECT_STREQ("7777", converter.solve("s").c_str());

	EXPECT_STREQ("8", converter.solve("t").c_str());
	EXPECT_STREQ("88", converter.solve("u").c_str());
	EXPECT_STREQ("888", converter.solve("v").c_str());

	EXPECT_STREQ("9", converter.solve("w").c_str());
	EXPECT_STREQ("99", converter.solve("x").c_str());
	EXPECT_STREQ("999", converter.solve("y").c_str());
	EXPECT_STREQ("9999", converter.solve("z").c_str());
}

TEST_F(Converter_test, check_words)
{
	EXPECT_STREQ("44 444",
		converter.solve("hi").c_str());

	EXPECT_STREQ("999337777",
		converter.solve("yes").c_str());

	EXPECT_STREQ("333666 6660 022 2777",
		converter.solve("foo  bar").c_str());

	EXPECT_STREQ("4433555 555666096667775553",
		converter.solve("hello world").c_str());
}

TEST_F(Converter_test, check_errors)
{
	EXPECT_THROW(converter.solve(""), std::invalid_argument);
	EXPECT_THROW(converter.solve("1"), std::invalid_argument);
	EXPECT_THROW(converter.solve("a1"), std::invalid_argument);
	EXPECT_THROW(converter.solve("1a"), std::invalid_argument);
	EXPECT_THROW(converter.solve("a1 a"), std::invalid_argument);
	EXPECT_THROW(converter.solve("a 1a"), std::invalid_argument);
}