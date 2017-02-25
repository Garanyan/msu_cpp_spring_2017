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

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
