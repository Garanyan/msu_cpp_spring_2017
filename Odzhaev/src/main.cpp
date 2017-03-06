#include "stdafx.h"

#include "translator.h"

int main(int argc, char** argv)
{
	int n;
	try
	{
		std::string str;
		std::getline(std::cin, str);
		n = std::stoi(str);
    	}
    	catch (...)
    	{
		std::cerr << "Incorrect input number of strings"<<std::endl;
		return EXIT_FAILURE;
	}
	Translator mutko;
	for (int i = 0; i < n; ++i)
	{
		std::string str;
		std::getline(std::cin, str);
		std::cout << "case #" << i + 1 << ": ";
		try
		{
			std::cout << mutko.translate(str);
		}
		catch(...)
		{
			std::cerr << "Incorrect input string"<<std::endl;
			return EXIT_FAILURE;
		}
		std::cout<<std::endl;
	}
	return EXIT_SUCCESS;
}
