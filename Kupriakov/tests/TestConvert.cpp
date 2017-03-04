#include "stdafx.h"
#include "../src/convert.h"
#include <string>

TEST(ConversionTest, GoogleTest1)
{
    std::string in = "hi";
    std::string out = "44 444";
    Converter c(in);
    std::string res;
    c.convertNextLine(res);
    ASSERT_STREQ(res.c_str(), out.c_str());
}

TEST(ConversionTest, GoogleTest2)
{
    std::string in = "yes";
    std::string out = "999337777";
    Converter c(in);
std::string res;
c.convertNextLine(res);
ASSERT_STREQ(res.c_str(), out.c_str());
}

TEST(ConversionTest, GoogleTest3)
{
    std::string in = "foo  bar";
    std::string out = "333666 6660 022 2777";
    Converter c(in);
std::string res;
c.convertNextLine(res);
ASSERT_STREQ(res.c_str(), out.c_str());
}

TEST(ConversionTest, GoogleTest4)
{
    std::string in = "hello world";
    std::string out = "4433555 555666096667775553";
    Converter c(in);
std::string res;
c.convertNextLine(res);
ASSERT_STREQ(res.c_str(), out.c_str());
}