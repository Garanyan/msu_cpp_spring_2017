#include <iostream>

#include "stdafx.h"

using namespace std;

class MyTesting : public ::testing::Test
{
		static Translator t;
		static void SetUpTestCase()  
		{
			cout << "Start" << endl;
		}
		static void TearDownTestCase()
		{
			cout << "Finish" << endl;
		}
		void SetUp() override {} 
		void TearDown() override {}
};

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
