#include "stdafx.h"

#include "t9.h"

int main(int argc, char* argv[])
{
    int numberOfCases;
    bool isFailed;

    do
    {
        std::cout << "Enter number of cases: ";
        std::cin >> numberOfCases;
        isFailed = std::cin.fail() || numberOfCases <= 0;
        if (isFailed)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: expected an integer value above zero." << std::endl;
        }
    } while (isFailed);
    std::cin.ignore();

    T9 t9;
    for (auto caseNumber = 0; caseNumber != numberOfCases; ++caseNumber)
    {
        std::string text;
        std::cout << "Enter text for case #" << caseNumber + 1 << ": ";
        std::getline(std::cin, text);
        std::cout << "Case #" << caseNumber + 1 << ": ";
        try
        {
            std::cout << t9.spell(text);
        }
        catch (std::invalid_argument & ia)
        {
            std::cout << "Error: " << ia.what() << '.';
        }
        std::cout << std::endl;
    }

    return 0;
}
