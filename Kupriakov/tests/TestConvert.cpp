#include "stdafx.h"
#include "../src/convert.h"

TEST(ConversionTest, GoogleTest)
{
    std::string input = "4\nhi\nyes\nfoo  bar\nhello world\n";
    std::string output = "Case #1: 44 444\nCase #2: 999337777\nCase #3: 333666 6660 022 2777\nCase #4: 4433555 555666096667775553\n";
    ASSERT_EQ(output, convert(input));
}
