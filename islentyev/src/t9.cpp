#include "stdafx.h"

#include "t9.h"

T9::T9()
{
    dict[' '] = { '0', 1 };

    char initialSymbol = '2';
    int shift = 0;
    int times = 1;

    char chars[] = { 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w' };
    int len = sizeof(chars) / sizeof(*chars);

    for (auto ch = 'a'; ch <= 'z'; ++ch)
    {
        if (shift < len - 1 && ch >= chars[shift + 1])
        {
            ++shift;
            times = 1;
        }
        dict[ch] = { static_cast<char>(initialSymbol + shift), times };
        ++times;
    }

 /* dict['a'] = { '2', 1 };
    dict['b'] = { '2', 2 };
    dict['c'] = { '2', 3 };
    dict['d'] = { '3', 1 };
    dict['e'] = { '3', 2 };
    dict['f'] = { '3', 3 };
    dict['g'] = { '4', 1 };
    dict['h'] = { '4', 2 };
    dict['i'] = { '4', 3 };
    dict['j'] = { '5', 1 };
    dict['k'] = { '5', 2 };
    dict['l'] = { '5', 3 };
    dict['m'] = { '6', 1 };
    dict['n'] = { '6', 2 };
    dict['o'] = { '6', 3 };
    dict['p'] = { '7', 1 };
    dict['q'] = { '7', 2 };
    dict['r'] = { '7', 3 };
    dict['s'] = { '7', 4 };
    dict['t'] = { '8', 1 };
    dict['u'] = { '8', 2 };
    dict['v'] = { '8', 3 };
    dict['w'] = { '9', 1 };
    dict['x'] = { '9', 2 };
    dict['y'] = { '9', 3 };
    dict['z'] = { '9', 4 }; */
}


std::string T9::spell(const std::string& text)
{
    if (text.empty())
        throw std::invalid_argument("text is empty");

    std::string result;
    char previousSymbol = -1;

    for(auto ch : text)
    {
        if (!dict.count(ch))
            throw std::invalid_argument("text contains invalid characters");

        auto sequence = dict[ch];

        if (previousSymbol == sequence.Symbol)
            result += ' ';

        for (auto i = 0; i != sequence.Times; ++i)
            result += sequence.Symbol;

        previousSymbol = sequence.Symbol;
    }

    return result;
}