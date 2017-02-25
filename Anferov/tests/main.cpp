#include "stdafx.h"

class T9_translater {
    string translate(string s) {
        /* need to implement */
        return string("");
    };
}

class TranslatingTest : public ::testing::Test
{
    T9_translater a;
    static void SetUpTestCase()  {}
    static void TearDownTestCase()  {}
};

TEST_F(TranslatingTest, OneLetter) {
    ASSERT_STREQ(a.translate("y"), "999");
}

TEST_F(TranslatingTest, SeveralOneDigitLetters) {
    ASSERT_STREQ(a.translate("qqq"), "77 77 77");
}

TEST_F(TranslatingTest, DifferentDigitsWord) {
    ASSERT_STREQ(a.translate("yes"), "999337777");
}

TEST_F(TranslatingTest, SameDigitsWord) {
    ASSERT_STREQ(a.translate("hello"), "4433555 555666");
}

TEST_F(TranslatingTest, SameDigitsWordSequence) {
    ASSERT_STREQ(a.translate("foo  bar"), "333666 6660 022 2777");
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
