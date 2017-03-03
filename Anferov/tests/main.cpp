#include "stdafx.h"
#include "../src/T9_translator.h"

using namespace std;

class TranslatingTest : public ::testing::Test
{
public:
    T9_translator a;
    static void SetUpTestCase()  {}
    static void TearDownTestCase()  {}
};

TEST_F(TranslatingTest, OneLetter) {
    EXPECT_STREQ(a.translate("a").c_str(), "2");
    EXPECT_STREQ(a.translate("k").c_str(), "55");
    EXPECT_STREQ(a.translate("o").c_str(), "666");
    EXPECT_STREQ(a.translate("p").c_str(), "7");
    EXPECT_STREQ(a.translate("s").c_str(), "7777");
    EXPECT_STREQ(a.translate("y").c_str(), "999");
    EXPECT_STREQ(a.translate("z").c_str(), "9999");
}

TEST_F(TranslatingTest, SeveralOneDigitLetters) {
    EXPECT_STREQ(a.translate("qqq").c_str(), "77 77 77");
}

TEST_F(TranslatingTest, DifferentDigitsWord) {
    EXPECT_STREQ(a.translate("yes").c_str(), "999337777");
}

TEST_F(TranslatingTest, SameDigitsWord) {
    EXPECT_STREQ(a.translate("hello").c_str(), "4433555 555666");
}

TEST_F(TranslatingTest, SameDigitsWordSequence) {
    EXPECT_STREQ(a.translate("foo  bar").c_str(), "333666 6660 022 2777");
}

TEST_F(TranslatingTest, UncorrectSymbols) {
    EXPECT_THROW(a.translate("asdAHG").c_str(), const char *);
    EXPECT_THROW(a.translate("3bn").c_str(), const char *);
    EXPECT_THROW(a.translate("ksg*&jh").c_str(), const char *);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
