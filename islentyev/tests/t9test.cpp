#include "stdafx.h"

#include "../src/t9.h"

class T9Test : public ::testing::Test
{
protected:
    T9 t9;
};

TEST_F(T9Test, SpellChars)
{
    EXPECT_STREQ(t9.spell("a").c_str(), "2");
    EXPECT_STREQ(t9.spell("b").c_str(), "22");
    EXPECT_STREQ(t9.spell("c").c_str(), "222");

    EXPECT_STREQ(t9.spell("d").c_str(), "3");
    EXPECT_STREQ(t9.spell("e").c_str(), "33");
    EXPECT_STREQ(t9.spell("f").c_str(), "333");

    EXPECT_STREQ(t9.spell("g").c_str(), "4");
    EXPECT_STREQ(t9.spell("h").c_str(), "44");
    EXPECT_STREQ(t9.spell("i").c_str(), "444");

    EXPECT_STREQ(t9.spell("j").c_str(), "5");
    EXPECT_STREQ(t9.spell("k").c_str(), "55");
    EXPECT_STREQ(t9.spell("l").c_str(), "555");

    EXPECT_STREQ(t9.spell("m").c_str(), "6");
    EXPECT_STREQ(t9.spell("n").c_str(), "66");
    EXPECT_STREQ(t9.spell("o").c_str(), "666");

    EXPECT_STREQ(t9.spell("p").c_str(), "7");
    EXPECT_STREQ(t9.spell("q").c_str(), "77");
    EXPECT_STREQ(t9.spell("r").c_str(), "777");
    EXPECT_STREQ(t9.spell("s").c_str(), "7777");

    EXPECT_STREQ(t9.spell("t").c_str(), "8");
    EXPECT_STREQ(t9.spell("u").c_str(), "88");
    EXPECT_STREQ(t9.spell("v").c_str(), "888");

    EXPECT_STREQ(t9.spell("w").c_str(), "9");
    EXPECT_STREQ(t9.spell("x").c_str(), "99");
    EXPECT_STREQ(t9.spell("y").c_str(), "999");
    EXPECT_STREQ(t9.spell("z").c_str(), "9999");

    EXPECT_STREQ(t9.spell(" ").c_str(), "0");
}

TEST_F(T9Test, SpellSentences)
{
    EXPECT_STREQ(t9.spell("yes").c_str(),
                 "999337777");

    EXPECT_STREQ(t9.spell("no").c_str(),
                 "66 666");

    EXPECT_STREQ(t9.spell("hi").c_str(),
                 "44 444");

    EXPECT_STREQ(t9.spell("foo  bar").c_str(),
                 "333666 6660 022 2777");

    EXPECT_STREQ(t9.spell("hello world").c_str(),
                 "4433555 555666096667775553");

    EXPECT_STREQ(t9.spell("the quick brown fox jumps over the lazy dog").c_str(),
                 "844330778844422255022777666966033366699058867 7777066688833777084433055529999 999036664");
}

TEST_F(T9Test, SpellErrors)
{
    EXPECT_THROW(t9.spell("").c_str(), std::invalid_argument);
    EXPECT_THROW(t9.spell("42").c_str(), std::invalid_argument);
    EXPECT_THROW(t9.spell("gds 4dsfh sd7").c_str(), std::invalid_argument);
    EXPECT_THROW(t9.spell("jskdf!").c_str(), std::invalid_argument);
}