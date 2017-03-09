#ifndef CONVERTER__H
#define CONVERTER_H

//#include <stdafx.h>
#include <string>
#include <vector>
#include <map>
#include <sstream>

class Converter
{
public:
    Converter(std::istream& s) : is(s) {fillKeypad(); fillKeytable();}
    Converter(std::string s) : iss(s), is(iss) {fillKeypad(); fillKeytable();}
    bool convertNextLine(std::string &line);

private:
    std::istringstream iss;
    std::istream &is;
    std::vector<std::string> keypad;
    std::map<char, std::pair<int, int> > keytable;
    void fillKeytable();
    void fillKeypad();
};

#endif
