#include "stdafx.h"
#include <map>
#include "header.h"

std::string T9::spell(const std::string& text)
{
	if (text == "")
		throw std::invalid_argument("Empty string");
	std::string result="";
	std::string pressDigit = "";
	char lastDigit = '#';
	for (unsigned int i = 0; i < text.length(); i++) {
		switch (text[i]) {
		case ' ':  pressDigit ="0"; break;
		case 'a':  pressDigit = "2"; break;
		case 'b':  pressDigit = "22"; break;
		case 'c':  pressDigit = "222"; break;
		case 'd':  pressDigit = "3"; break;
		case 'e':  pressDigit = "33"; break;
		case 'f':  pressDigit = "333"; break;
		case 'g':  pressDigit = "4"; break;
		case 'h':  pressDigit = "44"; break;
		case 'i':  pressDigit = "444"; break;
		case 'j':  pressDigit = "5"; break;
		case 'k':  pressDigit = "55"; break;
		case 'l':  pressDigit = "555"; break;
		case 'm':  pressDigit = "6"; break;
		case 'n':  pressDigit = "66"; break;
		case 'o':  pressDigit = "666"; break;
		case 'p':  pressDigit = "7"; break;
		case 'q':  pressDigit = "77"; break;
		case 'r':  pressDigit = "777"; break;
		case 's':  pressDigit = "7777"; break;
		case 't':  pressDigit = "8"; break;
		case 'u':  pressDigit = "88"; break;
		case 'v':  pressDigit = "888"; break;
		case 'w':  pressDigit = "9"; break;
		case 'x':  pressDigit = "99"; break;
		case 'y':  pressDigit = "999"; break;
		case 'z':  pressDigit = "9999"; break;
		default: throw std::invalid_argument("error"); break;
		}
		
		if (lastDigit == pressDigit.back()) {
			result += " ";
			result += pressDigit;
		}
		else {
			result += pressDigit;
		}
		lastDigit = pressDigit.back();	
	}
	return result;
}
