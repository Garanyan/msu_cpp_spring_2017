#include "stdafx.h"

using namespace std;

class T9_translater {
public:
    string translate(string s) {
        /* need to implement */
        return string("");
    };
};

class TranslatingTest : public ::testing::Test
{
public:
    T9_translater a;
    static void SetUpTestCase()  {}
    static void TearDownTestCase()  {}
};

TEST_F(TranslatingTest, OneLetter) {
    ASSERT_STREQ(a.translate("y").c_str(), "999");
}

TEST_F(TranslatingTest, SeveralOneDigitLetters) {
    ASSERT_STREQ(a.translate("qqq").c_str(), "77 77 77");
}

TEST_F(TranslatingTest, DifferentDigitsWord) {
    ASSERT_STREQ(a.translate("yes").c_str(), "999337777");
}

TEST_F(TranslatingTest, SameDigitsWord) {
    ASSERT_STREQ(a.translate("hello").c_str(), "4433555 555666");
}

TEST_F(TranslatingTest, SameDigitsWordSequence) {
    ASSERT_STREQ(a.translate("foo  bar").c_str(), "333666 6660 022 2777");
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
