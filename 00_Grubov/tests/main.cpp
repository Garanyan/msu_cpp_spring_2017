#include "stdafx.h"

TEST(Test, test1) {
    std::ofstream in; std::ifstream out;
    in << 1 << "\n";
    in << "a" << std::endl;
    solve(in, out);

    std::string data;
    ASSERT_EQ(out.eof(), false);
    out >> data;
    ASSERT_EQ(data, "Case #1: 2");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
