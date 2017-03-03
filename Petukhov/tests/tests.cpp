#include "stdafx.h"

#include "../src/t9translator.h"

class T9_test
    : public ::testing::Test
{
protected:
    T9Spell t9;
};

TEST_F(T9_test, spell_chars)
{
    EXPECT_STREQ("2", t9.translate("a").c_str());
    EXPECT_STREQ("22", t9.translate("b").c_str());
    EXPECT_STREQ("22", t9.translate("c").c_str());

    EXPECT_STREQ("3", t9.translate("d").c_str());
    EXPECT_STREQ("33", t9.translate("e").c_str());
    EXPECT_STREQ("33", t9.translate("f").c_str());

    EXPECT_STREQ("4", t9.translate("g").c_str());
    EXPECT_STREQ("44", t9.translate("h").c_str());
    EXPECT_STREQ("444", t9.translate("i").c_str());

    EXPECT_STREQ("5", t9.translate("j").c_str());
    EXPECT_STREQ("55", t9.translate("k").c_str());
    EXPECT_STREQ("555", t9.translate("l").c_str());

    EXPECT_STREQ("6", t9.translate("m").c_str());
    EXPECT_STREQ("66", t9.translate("n").c_str());
    EXPECT_STREQ("666", t9.translate("o").c_str());

    EXPECT_STREQ("7", t9.translate("p").c_str());
    EXPECT_STREQ("77", t9.translate("q").c_str());
    EXPECT_STREQ("777", t9.translate("r").c_str());
    EXPECT_STREQ("7777", t9.translate("s").c_str());

    EXPECT_STREQ("8", t9.translate("t").c_str());
    EXPECT_STREQ("88", t9.translate("u").c_str());
    EXPECT_STREQ("888", t9.translate("v").c_str());

    EXPECT_STREQ("9", t9.translate("w").c_str());
    EXPECT_STREQ("99", t9.translate("x").c_str());
    EXPECT_STREQ("999", t9.translate("y").c_str());
    EXPECT_STREQ("9999", t9.translate("z").c_str());
}

TEST_F(T9_test, spell_words)
{
    EXPECT_STREQ("44 444",
        t9.translate(" hi").c_str());

    EXPECT_STREQ("44 444",
        t9.translate("hi ").c_str());

    EXPECT_STREQ("44 444",
        t9.translate("hi").c_str());

    EXPECT_STREQ("999337777",
        t9.translate("yes").c_str());

    EXPECT_STREQ("333666 6660 022 2777",
        t9.translate("foo  bar").c_str());

    EXPECT_STREQ("4433555 555666096667775553",
        t9.translate("hello world").c_str());
}

TEST_F(T9_test, errors)
{
    EXPECT_THROW(t9.translate(""), std::invalid_argument);
    EXPECT_THROW(t9.translate("1"), std::invalid_argument);
    EXPECT_THROW(t9.translate("a1"), std::invalid_argument);
    EXPECT_THROW(t9.translate("1a"), std::invalid_argument);
    EXPECT_THROW(t9.translate("a1 a"), std::invalid_argument);
    EXPECT_THROW(t9.translate("a 1a"), std::invalid_argument);
}