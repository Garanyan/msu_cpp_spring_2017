#include "stdafx.h"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    TEST (T9_test, Test1)
    {
      ASSERT_STREQ(44 444, t9.solve("hi"))
    }
    TEST (T9_test, Test2)
    {
      ASSERT_STREQ(999337777, t9.solve("yes"))
    }
    TEST (T9_test, Test3)
    {
      ASSERT_STREQ(333666 6660 022 2777, t9.solve("foo bar"))
    }
    TEST (T9_test, Test4)
    {
      ASSERT_STREQ(4433555 555666096667775553, t9.solve("hello world"))
    }
    return RUN_ALL_TESTS();

}
