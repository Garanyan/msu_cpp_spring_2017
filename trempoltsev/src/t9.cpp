#include "stdafx.h"

#include "t9.h"

std::string T9::spell(const std::string& text)
{
    static const char PAUSE = ' ';

    static char const* const T9_SPACE = "0";

    static char const* const T9_BY_CHAR[] =
    {
        "2",    // a
        "22",   // b
        "222",  // c

        "3",    // d
        "33",   // e
        "333",  // f

        "4",    // g
        "44",   // h
        "444",  // i

        "5",    // j
        "55",   // k
        "555",  // l

        "6",    // m
        "66",   // n
        "666",  // o

        "7",    // p
        "77",   // q
        "777",  // r
        "7777", // s

        "8",    // t
        "88",   // u
        "888",  // v

        "9",    // w
        "99",   // x
        "999",  // y
        "9999", // z
    };

    if (text.empty())
        throw std::invalid_argument(std::string("empty string"));

    std::string result;

    for (auto c : text)
    {
        const char* sequence = nullptr;

        if (c == ' ')
            sequence = T9_SPACE;
        else if (c >= 'a' && c <= 'z')
            sequence = T9_BY_CHAR[c - 'a'];
        else
            throw std::invalid_argument(std::string("invalid char: '") + c + "'");

        if (!result.empty() && result.back() == sequence[0])
            result += PAUSE;

        result += sequence;
    }

    return result;
}
