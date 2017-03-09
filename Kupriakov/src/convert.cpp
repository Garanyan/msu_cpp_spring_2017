//#include "stdafx.h"
#include "convert.h"
#include <string>
#include <iostream>
#include <sstream>

static std::string intToString(int n)
{
    std::ostringstream strs;
    strs << n;
    return strs.str();
}

static std::string multiply(std::string s, size_t i)
{
    std::string r;
    while(i--)
        r += s;
    return r;
}

bool Converter::convertNextLine(std::string &line)
{
    line = "";
    std::string input_line;
    try
    {
        std::getline(is, input_line);
    }
    catch(const std::ios_base::failure& e)
    {
        std::cout << "Error: " << e.what();
        return false;
    }
    std::pair<int, int> prev = keytable[input_line[0]];
    line += multiply(intToString(prev.first), prev.second);
    for(size_t i = 1; i < input_line.length(); ++i)
    {
        if(keytable[input_line[i]].first == prev.first)
            line += " ";
        prev = keytable[input_line[i]];
        line += multiply(intToString(prev.first), prev.second);
    }
    return true;
}

void Converter::fillKeytable()
{
    for(unsigned key = 0; key < keypad.size(); ++key)
    {
        for (unsigned i = 0; i < keypad[key].length(); ++i)
        {
            keytable.insert(std::pair<char, std::pair<int, int> > (keypad[key][i], std::pair<int, int> (key, i + 1)));
        }
    }
}

void Converter::fillKeypad()
{
    std::string kp[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for(int i = 0; i < 10; ++i)
        keypad.push_back(kp[i]);
}
