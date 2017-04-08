#include "gtest/gtest.h"
#include "arsenal.hpp"
#include "storage.hpp"

class GameTests : public ::testing::Test
{
public:
    static arsenal a;
    static barracks b;
    static stadium s;
    
    static void SetUpTestCase();
    static void TearDownTestCase();
};
