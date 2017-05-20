#include "stdafx.h"

#include "t9.h"

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
	T9 mutko;
	for (int i = 0; i < n; ++i)
	{
		std::string str;
		std::getline(std::cin, str);
		std::cout << "Case #" << i + 1 << ": ";
		try
		{
			std::cout << mutko.translate(str)<<std::endl;
		}
		catch(std::invalid_argument& e)  
		{  
			std::cerr << e.what() << std::endl;  
			return EXIT_FAILURE;  
		} 
		catch(...)
		{
			std::cerr << "Incorrect input string"<<std::endl;
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
