#pragma once


#include <cstring>
#include <map>
#include <iostream>
#include <cstring>
#include <map>
#include <typeinfo>

using namespace std;
using std::string;
using std::map;
using std::pair;

static map<char, string> const initial_mapping = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}}
;

static const char empty_symbol = ' ';

class T9Translater {

public:

    std::string spell(const std::string& );
};
