#include "stdafx.h"

#include "../include/t9.h"

#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
	int n;

	try
	{
		std::string text;
		std::getline(std::cin, text);
		n = std::stoi(text);
	}
	catch (const std::invalid_argument&)
	{
		std::cerr << "Wrond usage\n";
		return EXIT_FAILURE;
	}

	T9 t9;

	for (int i = 0; i < n; i++)
	{
		std::string text;
		std::getline(std::cin, text);
		std::cout << "Case #" << i + 1 << ": ";
		try
		{
			std::cout << t9.spell(text);
		}
		catch (const std::invalid_argument& error)
		{
			std::cout << error.what();
		}
		catch (...)
		{
			std::cerr << "Unexpected exception caught\n";
			return EXIT_FAILURE;
		}

		std::cout << '\n';
	}
    return EXIT_SUCCESS;
}
