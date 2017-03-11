#include "stdafx.h"

#include "Converter.h"
#include <map>

std::string Converter::solve(const std::string& in)
{
	if (in == "")
		throw std::invalid_argument("Empty string");

	std::string result;
	std::string alphabet = "abc#def#ghi#jkl#mno#pqrs#tuv#wxyz";
	std::map<char, std::string> encoded_chars;
	int cur = 0;
	std::string s = "";
	for (int i = 0; i < alphabet.length(); i++) {
		if (alphabet[i] == '#') {
			cur++;
			s = "";
		}
		else {
			s += ('2' + cur);
			encoded_chars[alphabet[i]] = s;
		}
	}
	encoded_chars[' '] = '0';

	char last_symbol = '#';
	for (long i = 0; i < in.length(); i++) {
		if ( (in[i] <= 'z') && (in[i] >= 'a') || (in[i] == ' ') ) {
			if (last_symbol == encoded_chars[in[i]][0])
				result += ' ';
			result += encoded_chars[in[i]];
			last_symbol = encoded_chars[in[i]][0];
		}
		else {
			throw std::invalid_argument("Invalid symbol");
		}
	}

	return result;
}