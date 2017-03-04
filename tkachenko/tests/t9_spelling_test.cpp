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
   EXPECT_STREQ("2", t9_spelling.getCodeForLetter('a').c_str());
   EXPECT_STREQ("22", t9_spelling.getCodeForLetter('b').c_str());
   EXPECT_STREQ("222", t9_spelling.getCodeForLetter('c').c_str());

   EXPECT_STREQ("3", t9_spelling.getCodeForLetter('d').c_str());
   EXPECT_STREQ("33", t9_spelling.getCodeForLetter('e').c_str());
   EXPECT_STREQ("333", t9_spelling.getCodeForLetter('f').c_str());

   EXPECT_STREQ("4", t9_spelling.getCodeForLetter('g').c_str());
   EXPECT_STREQ("44", t9_spelling.getCodeForLetter('h').c_str());
   EXPECT_STREQ("444", t9_spelling.getCodeForLetter('i').c_str());

   EXPECT_STREQ("5", t9_spelling.getCodeForLetter('j').c_str());
   EXPECT_STREQ("55", t9_spelling.getCodeForLetter('k').c_str());
   EXPECT_STREQ("555", t9_spelling.getCodeForLetter('l').c_str());

   EXPECT_STREQ("6", t9_spelling.getCodeForLetter('m').c_str());
   EXPECT_STREQ("66", t9_spelling.getCodeForLetter('n').c_str());
   EXPECT_STREQ("666", t9_spelling.getCodeForLetter('o').c_str());

    EXPECT_STREQ("7", t9_spelling.getCodeForLetter('p').c_str());
    EXPECT_STREQ("77", t9_spelling.getCodeForLetter('q').c_str());
    EXPECT_STREQ("777", t9_spelling.getCodeForLetter('r').c_str());
    EXPECT_STREQ("7777", t9_spelling.getCodeForLetter('s').c_str());

    EXPECT_STREQ("8", t9_spelling.getCodeForLetter('t').c_str());
    EXPECT_STREQ("88", t9_spelling.getCodeForLetter('u').c_str());
    EXPECT_STREQ("888", t9_spelling.getCodeForLetter('v').c_str());

    EXPECT_STREQ("9", t9_spelling.getCodeForLetter('w').c_str());
    EXPECT_STREQ("99", t9_spelling.getCodeForLetter('x').c_str());
    EXPECT_STREQ("999", t9_spelling.getCodeForLetter('y').c_str());
    EXPECT_STREQ("9999", t9_spelling.getCodeForLetter('z').c_str());

    EXPECT_STREQ("0", t9_spelling.getCodeForLetter(' ').c_str());


}

TEST_F(T9_Spelling_Test, spell_equal_letters)
{
    EXPECT_STREQ("2 2",
        t9_spelling.spell("aa").c_str());

    EXPECT_STREQ("02 2",
        t9_spelling.spell(" aa").c_str());

	EXPECT_STREQ("9999 9999",
        	t9_spelling.spell("zz").c_str());
	
	EXPECT_STREQ("999909999",
        	t9_spelling.spell("z z").c_str());
}

TEST_F(T9_Spelling_Test, spell_words)
{
    EXPECT_STREQ("044 444",
        t9_spelling.spell(" hi").c_str());

    EXPECT_STREQ("44 4440",
        t9_spelling.spell("hi ").c_str());

    EXPECT_STREQ("44 444",
        t9_spelling.spell("hi").c_str());

    EXPECT_STREQ("999337777",
        t9_spelling.spell("yes").c_str());

    EXPECT_STREQ("333666 6660 022 2777",
        t9_spelling.spell("foo  bar").c_str());

    EXPECT_STREQ("4433555 555666096667775553",
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


