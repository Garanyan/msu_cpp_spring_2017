#include "stdafx.h"
#include "../include/T9Speller.h"


class T9Speller_test
    : public ::testing::Test
{
protected:
    T9Speller instance;
};


TEST_F(T9Speller_test, spell_chars)
{
    EXPECT_STREQ("2", instance.spell("a").c_str());
    EXPECT_STREQ("22", instance.spell("b").c_str());
    EXPECT_STREQ("222", instance.spell("c").c_str());

    EXPECT_STREQ("3", instance.spell("d").c_str());
    EXPECT_STREQ("33", instance.spell("e").c_str());
    EXPECT_STREQ("333", instance.spell("f").c_str());

    EXPECT_STREQ("4", instance.spell("g").c_str());
    EXPECT_STREQ("44", instance.spell("h").c_str());
    EXPECT_STREQ("444", instance.spell("i").c_str());

    EXPECT_STREQ("5", instance.spell("j").c_str());
    EXPECT_STREQ("55", instance.spell("k").c_str());
    EXPECT_STREQ("555", instance.spell("l").c_str());

    EXPECT_STREQ("6", instance.spell("m").c_str());
    EXPECT_STREQ("66", instance.spell("n").c_str());
    EXPECT_STREQ("666", instance.spell("o").c_str());

    EXPECT_STREQ("7", instance.spell("p").c_str());
    EXPECT_STREQ("77", instance.spell("q").c_str());
    EXPECT_STREQ("777", instance.spell("r").c_str());
    EXPECT_STREQ("7777", instance.spell("s").c_str());

    EXPECT_STREQ("8", instance.spell("t").c_str());
    EXPECT_STREQ("88", instance.spell("u").c_str());
    EXPECT_STREQ("888", instance.spell("v").c_str());

    EXPECT_STREQ("9", instance.spell("w").c_str());
    EXPECT_STREQ("99", instance.spell("x").c_str());
    EXPECT_STREQ("999", instance.spell("y").c_str());
    EXPECT_STREQ("9999", instance.spell("z").c_str());
    
    EXPECT_STREQ("0", instance.spell(" ").c_str());
}

TEST_F(T9Speller_test, spell_words)
{
    EXPECT_STREQ("044 444",
        instance.spell(" hi").c_str());

    EXPECT_STREQ("44 4440",
        instance.spell("hi ").c_str());

    EXPECT_STREQ("44 444",
        instance.spell("hi").c_str());

    EXPECT_STREQ("999337777",
        instance.spell("yes").c_str());

    EXPECT_STREQ("333666 6660 022 2777",
        instance.spell("foo  bar").c_str());

    EXPECT_STREQ("4433555 555666096667775553",
        instance.spell("hello world").c_str());
}

TEST_F(T9Speller_test, errors)
{
    EXPECT_THROW(instance.spell(""), std::invalid_argument);
    EXPECT_THROW(instance.spell("1"), std::invalid_argument);
    EXPECT_THROW(instance.spell("a1"), std::invalid_argument);
    EXPECT_THROW(instance.spell("1a"), std::invalid_argument);
    EXPECT_THROW(instance.spell("a1 a"), std::invalid_argument);
    EXPECT_THROW(instance.spell("a 1a"), std::invalid_argument);
}
