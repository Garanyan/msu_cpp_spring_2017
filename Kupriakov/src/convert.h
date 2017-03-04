#ifndef CONVERTER__H
#define CONVERTER_H

//#include <stdafx.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

class Converter
{
public:
    Converter(std::istream& s) : is {s} {fillKeytable();}
    Converter(std::string s) : iss{std::move(s)} {fillKeytable();}
    bool convertNextLine(std::string &line);

private:
    std::istringstream iss {};
    std::istream &is {iss};
    std::vector<std::string> keypad = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::unordered_map<char, std::pair<int, int> > keytable;
    void fillKeytable();
};

#endif
