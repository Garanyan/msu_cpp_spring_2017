#include "stdafx.h"

#include "Converter.h"

int main(int /*argc*/, char** /*argv*/)
{
	int n = 0;

	try
	{
		std::string text;
		std::getline(std::cin, text);
		n = std::stoi(text);
	}
	catch (const std::invalid_argument&)
	{
		std::cerr << "invalid number of tests\n";
		return EXIT_FAILURE;
	}

	Converter converter;

	for (int i = 0; i < n; i++)
	{
		std::string text;
		std::getline(std::cin, text);

		std::cout << "case #" << i + 1 << ": ";

		try
		{
			std::cout << converter.solve(text);
		}
		catch (const std::invalid_argument& error)
		{
			std::cout << error.what();
		}
		catch (...)
		{
			std::cerr << "unexpected error\n";
			return EXIT_FAILURE;
		}

		std::cout << '\n';
	}

	return EXIT_SUCCESS;
}
