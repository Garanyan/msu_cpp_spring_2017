#include "stdafx.h"
#include "Task.h"

TEST(Test, test1) {
    std::vector<std::string> input;
    input.push_back("a");

    auto answ = solve(input);
    ASSERT_STREQ(answ[0].c_str(), "2");
}

TEST(Test, test2) {
    std::vector<std::string> input;
    input.push_back("abc");

    auto answ = solve(input);
    ASSERT_STREQ(answ[0].c_str(), "2 22 222");
}

TEST(Test, test3) {
    std::vector<std::string> input = { "cba", "azza", "adgjmptw" };

    auto answ = solve(input);
    ASSERT_STREQ(answ[0].c_str(), "222 22 2");
    ASSERT_STREQ(answ[1].c_str(), "29999 99992");
    ASSERT_STREQ(answ[2].c_str(), "23456789");
}

TEST(Test, test4) {
    std::vector<std::string> input = { "hello world" };

    auto answ = solve(input);
    ASSERT_STREQ(answ[0].c_str(), "4433555 555666096667775553");
}

TEST(Test, test5) {
    std::vector<std::string> input = { "hi", "yes", "foo  bar" };
    auto answ = solve(input);
    ASSERT_STREQ(answ[0].c_str(), "44 444");
    ASSERT_STREQ(answ[1].c_str(), "999337777");
    ASSERT_STREQ(answ[2].c_str(), "333666 6660 022 2777");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
