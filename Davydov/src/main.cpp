#include "stdafx.h"
#include <string>
#include <iostream>
#include <t9transform.h>

int main(int argc, char* argv[])
{
	std::string str;
	std::getline(std::cin, str);
	std::cout << transform(str) << std::endl;
	return 0;
}
