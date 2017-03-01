# include "stdafx.h"
# include "../include/T9Speller.h"
# include <iostream>

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char* argv[])
{
	int N = 0;
	cout << "Enter the number of test cases (1 < N < 100): ";
	try
	{
		string input;
		std::getline(std::cin, input);
		N = std::stoi(input);
		if (N < 1 || N > 100) throw std::invalid_argument("number of test cases must be greater than 1 and less than 100");
	}
	catch (std::invalid_argument const & err)
	{
		std::cerr << "Error while entering the number of cases: " + string(err.what()) << endl;
		return EXIT_FAILURE;
	}

	T9Speller spl;
	cout << "Enter test cases:\n";
	for (int i = 0; i < N; ++i)
	{
		std::string text;
		std::getline(std::cin, text);
		std::cout << "Case #" << i + 1 << ": ";

		try
		{
			std::cout << spl.spell(text);
		}
		catch (std::invalid_argument const & err)
		{
			std::cout << "Error while processing text: " + string(err.what());
		}
		catch (...)
		{
			std::cerr << "Unexpected error!\n";
			return EXIT_FAILURE;
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}

