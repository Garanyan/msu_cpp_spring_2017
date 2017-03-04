#include "stdafx.h"

#include "../src/t9_spelling.h"

class T9_Spelling_Test
    : public ::testing::Test
{
protected:
    T9_Spelling t9_spelling;
};


TEST_F(T9_Spelling_Test, spell_letters)
{
    ASSERT_EQ("2", t9_spelling.spell("a").c_str());
    ASSERT_EQ("22", t9_spelling.spell("b").c_str());
    ASSERT_EQ("222", t9_spelling.spell("c").c_str());

    ASSERT_EQ("3", t9_spelling.spell("d").c_str());
    ASSERT_EQ("33", t9_spelling.spell("e").c_str());
    ASSERT_EQ("333", t9_spelling.spell("f").c_str());

    ASSERT_EQ("4", t9_spelling.spell("g").c_str());
    ASSERT_EQ("44", t9_spelling.spell("h").c_str());
    ASSERT_EQ("444", t9_spelling.spell("i").c_str());

    ASSERT_EQ("5", t9_spelling.spell("j").c_str());
    ASSERT_EQ("55", t9_spelling.spell("k").c_str());
    ASSERT_EQ("555", t9_spelling.spell("l").c_str());

    ASSERT_EQ("6", t9_spelling.spell("m").c_str());
    ASSERT_EQ("66", t9_spelling.spell("n").c_str());
    ASSERT_EQ("666", t9_spelling.spell("o").c_str());

    ASSERT_EQ("7", t9_spelling.spell("p").c_str());
    ASSERT_EQ("77", t9_spelling.spell("q").c_str());
    ASSERT_EQ("777", t9_spelling.spell("r").c_str());
    ASSERT_EQ("7777", t9_spelling.spell("s").c_str());

    ASSERT_EQ("8", t9_spelling.spell("t").c_str());
    ASSERT_EQ("88", t9_spelling.spell("u").c_str());
    ASSERT_EQ("888", t9_spelling.spell("v").c_str());

    ASSERT_EQ("9", t9_spelling.spell("w").c_str());
    ASSERT_EQ("99", t9_spelling.spell("x").c_str());
    ASSERT_EQ("999", t9_spelling.spell("y").c_str());
    ASSERT_EQ("9999", t9_spelling.spell("z").c_str());

    ASSERT_EQ("0", t9_spelling.spell(" ").c_str());


}

TEST_F(T9_Spelling_Test, spell_equal_letters)
{
    ASSERT_EQ("2 2",
        t9_spelling.spell("aa").c_str());

    ASSERT_EQ("02 2",
        t9_spelling.spell(" aa").c_str());

	ASSERT_EQ("9999 9999",
        	t9_spelling.spell("zz").c_str());
	
	ASSERT_EQ("999909999",
        	t9_spelling.spell("z z").c_str());
}

TEST_F(T9_Spelling_Test, spell_words)
{
    ASSERT_EQ("44 444",
        t9_spelling.spell(" hi").c_str());

    ASSERT_EQ("44 444",
        t9_spelling.spell("hi ").c_str());

    ASSERT_EQ("44 444",
        t9_spelling.spell("hi").c_str());

    ASSERT_EQ("999337777",
        t9_spelling.spell("yes").c_str());

    ASSERT_EQ("333666 6660 022 2777",
        t9_spelling.spell("foo  bar").c_str());

    ASSERT_EQ("4433555 555666096667775553",
        t9_spelling.spell("hello world").c_str());
}

TEST_F(T9_Spelling_Test, errors)
{
    EXPECT_THROW(t9.spell(""), std::invalid_argument);
    EXPECT_THROW(t9.spell("1"), std::invalid_argument);
    EXPECT_THROW(t9.spell("a1"), std::invalid_argument);
    EXPECT_THROW(t9.spell("1a"), std::invalid_argument);
    EXPECT_THROW(t9.spell("a1 a"), std::invalid_argument);
    EXPECT_THROW(t9.spell("a 1a"), std::invalid_argument);
}


