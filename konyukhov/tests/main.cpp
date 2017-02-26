#include "stdafx.h"
#include "translater.hpp"

class TranslaterTest : public testing::Test {
public:
    TextOnNineTranslater t;
    static void SetUpTestCase() {}
    static void TearDownTestCase() {}
};

TEST_F(TranslaterTest, OneLetter) {
    ASSERT_STREQ(t.translateString("y").c_str(), "999");
}

TEST_F(TranslaterTest, SeveralOneDigitLetters) {
    ASSERT_STREQ(t.translateString("qqq").c_str(), "77 77 77");
}

TEST_F(TranslaterTest, DifferentDigitsWord) {
    ASSERT_STREQ(t.translateString("yes").c_str(), "999337777");
}

TEST_F(TranslaterTest, SameDigitsWord) {
    ASSERT_STREQ(t.translateString("hello").c_str(), "4433555 555666");
}

TEST_F(TranslaterTest, SameDigitsWordSequence) {
    ASSERT_STREQ(t.translateString("foo  bar").c_str(), "333666 6660 022 2777");
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
