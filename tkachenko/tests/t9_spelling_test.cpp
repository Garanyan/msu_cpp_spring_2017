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
    ASSERT_EQ("2", t9_spelling.getCodeForLetter('a').c_str());
    ASSERT_EQ("22", t9_spelling.getCodeForLetter('b').c_str());
    ASSERT_EQ("222", t9_spelling.getCodeForLetter('c').c_str());

    ASSERT_EQ("3", t9_spelling.getCodeForLetter('d').c_str());
    ASSERT_EQ("33", t9_spelling.getCodeForLetter('e').c_str());
    ASSERT_EQ("333", t9_spelling.getCodeForLetter('f').c_str());

    ASSERT_EQ("4", t9_spelling.getCodeForLetter('g').c_str());
    ASSERT_EQ("44", t9_spelling.getCodeForLetter('h').c_str());
    ASSERT_EQ("444", t9_spelling.getCodeForLetter('i').c_str());

    ASSERT_EQ("5", t9_spelling.getCodeForLetter('j').c_str());
    ASSERT_EQ("55", t9_spelling.getCodeForLetter('k').c_str());
    ASSERT_EQ("555", t9_spelling.getCodeForLetter('l').c_str());

    ASSERT_EQ("6", t9_spelling.getCodeForLetter('m').c_str());
    ASSERT_EQ("66", t9_spelling.getCodeForLetter('n').c_str());
    ASSERT_EQ("666", t9_spelling.getCodeForLetter('o').c_str());

    ASSERT_EQ("7", t9_spelling.getCodeForLetter('p').c_str());
    ASSERT_EQ("77", t9_spelling.getCodeForLetter('q').c_str());
    ASSERT_EQ("777", t9_spelling.getCodeForLetter('r').c_str());
    ASSERT_EQ("7777", t9_spelling.getCodeForLetter('s').c_str());

    ASSERT_EQ("8", t9_spelling.getCodeForLetter('t').c_str());
    ASSERT_EQ("88", t9_spelling.getCodeForLetter('u').c_str());
    ASSERT_EQ("888", t9_spelling.getCodeForLetter('v').c_str());

    ASSERT_EQ("9", t9_spelling.getCodeForLetter('w').c_str());
    ASSERT_EQ("99", t9_spelling.getCodeForLetter('x').c_str());
    ASSERT_EQ("999", t9_spelling.getCodeForLetter('y').c_str());
    ASSERT_EQ("9999", t9_spelling.getCodeForLetter('z').c_str());

    ASSERT_EQ("0", t9_spelling.getCodeForLetter(' ').c_str());


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
    	EXPECT_THROW(t9_spelling.spell(""), std::invalid_argument);
    	EXPECT_THROW(t9_spelling.spell("1"), std::invalid_argument);
    	EXPECT_THROW(t9_spelling.spell("a1"), std::invalid_argument);
    	EXPECT_THROW(t9_spelling.spell("1a"), std::invalid_argument);
    	EXPECT_THROW(t9_spelling.spell("a1 a"), std::invalid_argument);
    	EXPECT_THROW(t9_spelling.spell("a 1a"), std::invalid_argument);
	EXPECT_THROW(t9_spelling.getCodeForLetter('1'), std::invalid_argument);
	EXPECT_THROW(t9_spelling.getCodeForLetter('A'), std::invalid_argument);
	EXPECT_THROW(t9_spelling.getCodeForLetter('/'), std::invalid_argument);
}


