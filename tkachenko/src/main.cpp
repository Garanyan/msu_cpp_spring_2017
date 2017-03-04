#include "stdafx.h"

#include "t9_spelling.h"

int main(int /*argc*/, char** /*argv*/)
{
    int n = 0;

    try
    {
        std::string text;
        std::getline(std::cin, text);
        n = std::stoi(text);
    }
    catch (const std::invalid_argument& error)
    {
        std::cerr << "usage: \n";
        std::cerr << "The first line of input gives the number of cases, N. N test cases "
                     "follow. Each case is a line of text formatted as\n\n"
                     "    desired message\n\n"
                     "Each message will consist of only lowercase characters a-z and space "
                     "characters.\n";
        return EXIT_FAILURE;
    }

    T9_spelling t9_spelling;

    for (int i = 0; i < n; ++i)
    {
        std::string text;
        std::getline(std::cin, text);

        std::cout << "case #" << i + 1 << ": ";

        try
        {
            std::cout << t9_spelling.spell(text);
        }
        catch (const std::invalid_argument& error)
        {
            std::cout << error.what();
		return EXIT_FAILURE;
        }
        catch(...)
        {
            std::cerr << "unexpected error\n";
            return EXIT_FAILURE;
        }

        std::cout << '\n';
    }

    return EXIT_SUCCESS;
}
