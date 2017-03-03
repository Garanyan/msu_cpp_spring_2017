#include "stdafx.h"

#include "Converter.h"
#include <map>

std::string Converter::solve(const std::string& in)
{
	if (in == "")
		throw std::invalid_argument("Empty string");

	std::string result;
	int mas[8] = {2, 5, 8, 11, 14, 18, 21, 26};
	std::map<char, std::string> m;
	int cur = 0;
	std::string s = "";
	for (char i = 'a'; i <= 'z'; i++) {
		if (i - 'a' > mas[cur]) {
			cur++;
			s = "";
		}
		s += ('2' + cur);
		m[i] = s;
	}
	m[' '] = '0';

	char last = '#';
	for (long i = 0; i < in.length(); i++) {
		if ( (in[i] <= 'z') && (in[i] >= 'a') || (in[i] == ' ') ) {
			if (last == m[in[i]][0])
				result += ' ';
			result += m[in[i]];
			last = m[in[i]][0];
		}
		else {
			throw std::invalid_argument("Invalid symbol");
		}
	}

	return result;
}