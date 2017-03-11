#include "stdafx.h"

#include "../src/t9.h"

TEST(T9_test, spell_chars)
{
    EXPECT_STREQ("2", t9_translate("a").c_str());
    EXPECT_STREQ("22", t9_translate("b").c_str());
    EXPECT_STREQ("222", t9_translate("c").c_str());

    EXPECT_STREQ("3", t9_translate("d").c_str());
    EXPECT_STREQ("33", t9_translate("e").c_str());
    EXPECT_STREQ("333", t9_translate("f").c_str());

    EXPECT_STREQ("4", t9_translate("g").c_str());
    EXPECT_STREQ("44", t9_translate("h").c_str());
    EXPECT_STREQ("444", t9_translate("i").c_str());

    EXPECT_STREQ("5", t9_translate("j").c_str());
    EXPECT_STREQ("55", t9_translate("k").c_str());
    EXPECT_STREQ("555", t9_translate("l").c_str());

    EXPECT_STREQ("6", t9_translate("m").c_str());
    EXPECT_STREQ("66", t9_translate("n").c_str());
    EXPECT_STREQ("666", t9_translate("o").c_str());

    EXPECT_STREQ("7", t9_translate("p").c_str());
    EXPECT_STREQ("77", t9_translate("q").c_str());
    EXPECT_STREQ("777", t9_translate("r").c_str());
    EXPECT_STREQ("7777", t9_translate("s").c_str());

    EXPECT_STREQ("8", t9_translate("t").c_str());
    EXPECT_STREQ("88", t9_translate("u").c_str());
    EXPECT_STREQ("888", t9_translate("v").c_str());

    EXPECT_STREQ("9", t9_translate("w").c_str());
    EXPECT_STREQ("99", t9_translate("x").c_str());
    EXPECT_STREQ("999", t9_translate("y").c_str());
    EXPECT_STREQ("9999", t9_translate("z").c_str());
}

TEST(T9_test, spell_words)
{
    EXPECT_STREQ("0 044 444",
        t9_translate("  hi").c_str());

    EXPECT_STREQ("044 444",
        t9_translate(" hi").c_str());

    EXPECT_STREQ("44 4440",
        t9_translate("hi ").c_str());

    EXPECT_STREQ("44 4440 0",
        t9_translate("hi  ").c_str());

    EXPECT_STREQ("44 444",
        t9_translate("hi").c_str());

    EXPECT_STREQ("999337777",
        t9_translate("yes").c_str());

    EXPECT_STREQ("333666 6660 022 2777",
        t9_translate("foo  bar").c_str());

    EXPECT_STREQ("4433555 555666096667775553",
        t9_translate("hello world").c_str());
}

TEST_F(T9_test, errors)
{
        EXPECT_THROW(t9_translate(""), std::invalid_argument);
        EXPECT_THROW(t9_translate("1"), std::invalid_argument);
        EXPECT_THROW(t9_translate("a1"), std::invalid_argument);
        EXPECT_THROW(t9_translate("1a"), std::invalid_argument);
        EXPECT_THROW(t9_translate("a1 a"), std::invalid_argument);
        EXPECT_THROW(t9_translate("a 1a"), std::invalid_argument);
}
