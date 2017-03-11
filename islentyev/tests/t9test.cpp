#include "stdafx.h"

#include "t9.h"

class T9Test : public ::testing::Test
{
protected:
    T9 t9;
};

TEST_F(T9Test, SpellChars)
{
    EXPECT_STREQ("2", t9.spell("a").c_str());
    EXPECT_STREQ("22", t9.spell("b").c_str());
    EXPECT_STREQ("222", t9.spell("c").c_str());

    EXPECT_STREQ("3", t9.spell("d").c_str());
    EXPECT_STREQ("33", t9.spell("e").c_str());
    EXPECT_STREQ("333", t9.spell("f").c_str());

    EXPECT_STREQ("4", t9.spell("g").c_str());
    EXPECT_STREQ("44", t9.spell("h").c_str());
    EXPECT_STREQ("444", t9.spell("i").c_str());

    EXPECT_STREQ("5", t9.spell("j").c_str());
    EXPECT_STREQ("55", t9.spell("k").c_str());
    EXPECT_STREQ("555", t9.spell("l").c_str());

    EXPECT_STREQ("6", t9.spell("m").c_str());
    EXPECT_STREQ("66", t9.spell("n").c_str());
    EXPECT_STREQ("666", t9.spell("o").c_str());

    EXPECT_STREQ("7", t9.spell("p").c_str());
    EXPECT_STREQ("77", t9.spell("q").c_str());
    EXPECT_STREQ("777", t9.spell("r").c_str());
    EXPECT_STREQ("7777", t9.spell("s").c_str());

    EXPECT_STREQ("8", t9.spell("t").c_str());
    EXPECT_STREQ("88", t9.spell("u").c_str());
    EXPECT_STREQ("888", t9.spell("v").c_str());

    EXPECT_STREQ("9", t9.spell("w").c_str());
    EXPECT_STREQ("99", t9.spell("x").c_str());
    EXPECT_STREQ("999", t9.spell("y").c_str());
    EXPECT_STREQ("9999", t9.spell("z").c_str());

    EXPECT_STREQ("0", t9.spell(" ").c_str());
}

TEST_F(T9Test, SpellSentences)
{
    EXPECT_STREQ("999337777",
                 t9.spell("yes").c_str());

    EXPECT_STREQ("66 666",
                 t9.spell("no").c_str());

    EXPECT_STREQ("44 444",
                 t9.spell("hi").c_str());

    EXPECT_STREQ("333666 6660 022 2777",
                 t9.spell("foo  bar").c_str());

    EXPECT_STREQ("4433555 555666096667775553",
                 t9.spell("hello world").c_str());

    EXPECT_STREQ("844330778844422255022777666966033366699058867 7777066688833777084433055529999 999036664",
                 t9.spell("the quick brown fox jumps over the lazy dog").c_str());
}

TEST_F(T9Test, SpellErrors)
{
    EXPECT_THROW(t9.spell("").c_str(), std::invalid_argument);
    EXPECT_THROW(t9.spell("42").c_str(), std::invalid_argument);
    EXPECT_THROW(t9.spell("gds 4dsfh sd7").c_str(), std::invalid_argument);
    EXPECT_THROW(t9.spell("jskdf!").c_str(), std::invalid_argument);
}
