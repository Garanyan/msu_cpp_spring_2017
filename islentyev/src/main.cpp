#include "stdafx.h"

#include "t9.h"

int main(int argc, char* argv[])
{
    int numberOfCases;
    std::cin >> numberOfCases;
    std::cin.ignore();
    T9 t9;
    for (auto caseNumber = 0; caseNumber != numberOfCases; ++caseNumber)
    {
        std::string text;
        std::getline(std::cin, text);
        std::cout << "Case #" << caseNumber + 1 << ": ";
        try
        {
            std::cout << t9.spell(text);
        }
        catch(std::invalid_argument & ia)
        {
            std::cout << "Error: " << ia.what();
        }
        std::cout << std::endl;
    }
    return 0;
}
