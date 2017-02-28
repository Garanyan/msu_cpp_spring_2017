#include "stdafx.h"

#include "t9.h"

std::string T9::char_code(const char c) {
    return
    (c == 'a') ? "2"    :
    (c == 'b') ? "22"   :
    (c == 'c') ? "222"  :
    (c == 'd') ? "3"    :
    (c == 'e') ? "33"   :
    (c == 'f') ? "333"  :
    (c == 'g') ? "4"    :
    (c == 'h') ? "44"   :
    (c == 'i') ? "444"  :
    (c == 'j') ? "5"    :
    (c == 'k') ? "55"   :
    (c == 'l') ? "555"  :
    (c == 'm') ? "6"    :
    (c == 'n') ? "66"   :
    (c == 'o') ? "666"  :
    (c == 'p') ? "7"    :
    (c == 'q') ? "77"   :
    (c == 'r') ? "777"  :
    (c == 's') ? "7777" :
    (c == 't') ? "8"    :
    (c == 'u') ? "88"   :
    (c == 'v') ? "888"  :
    (c == 'w') ? "9"    :
    (c == 'x') ? "99"   :
    (c == 'y') ? "999"  :
    (c == 'z') ? "9999" :
    (c == ' ') ? "0"    : "" ;
}

std::string T9::spell(const std::string& text)
{
    if (text.empty()) throw std::invalid_argument("string is empty");
    std::string result;
    int i=0;
    while( char_code(text[i]) == "0" && i<text.length() ) i++;
    for (i; i<text.length(); i++) {
        char curr = text[i];
	std::string code = char_code(curr);
	if (code.empty()) throw std::invalid_argument( std::string("bad simbol") + curr );
        if (result.back() == code[0]) result += " ";
	result += code;
    }
    while(result.back() == '0') result.pop_back();
    return result;
}
