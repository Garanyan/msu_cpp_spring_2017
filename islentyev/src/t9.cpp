#include "stdafx.h"

#include "t9.h"

T9::T9()
{
    const std::map<char, std::string> keypad
        {
            { '2', "abc" },
            { '3', "def" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8', "tuv" },
            { '9', "wxyz"},
            { '0', " " }
        };

    for (auto button : keypad)
    {
        auto symbol = button.first;
        auto characters = button.second;

        for (auto it = characters.begin(); it != characters.end(); ++it)
            dictionary[*it] = { symbol, static_cast<unsigned>(it - characters.begin() + 1) };
    }
}

std::string T9::spell(const std::string &text)
{
    if (text.empty())
        throw std::invalid_argument("text is empty");

    std::string result;
    char previousSymbol = -1;

    for (auto character : text)
    {
        if (!dictionary.count(character))
            throw std::invalid_argument("text contains invalid characters");

        auto sequence = dictionary[character];

        if (previousSymbol == sequence.Symbol)
            result += ' ';
        result.append(sequence.Times, sequence.Symbol);
        previousSymbol = sequence.Symbol;
    }

    return result;
}
