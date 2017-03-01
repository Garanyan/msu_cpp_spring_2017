#include "stdafx.h"
#include "t9sol.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::string str;
	std::getline(std::cin, str);
	std::cout << t9solve(str) << std::endl;
    return 0;
}
