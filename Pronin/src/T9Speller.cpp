# include "stdafx.h"
# include "../include/T9Speller.h"


T9Speller::T9Speller(map<char, string> const & buttons_layout) : buttons_layout(buttons_layout)
{
	for (auto button : buttons_layout)
		for (size_t i = 0; i < button.second.size(); ++i)
			layout_mapping[button.second[i]] = pair<char, size_t>(button.first, i + 1);
}

T9Speller::~T9Speller(){}

string T9Speller::spell(string const & str)
{
	if (!str.size()) throw std::invalid_argument("empty input string");
	string res = "";
	for (size_t i = 0; i < str.size() - 1; ++i)
	{
		char letter = str[i];
		char next_letter = str[i + 1];
		if (!(letter >= 'a' && letter <= 'z' || letter == ' ')) throw std::invalid_argument("unexpected symbol in input string : " + string(1, letter));
		pair<char, size_t> letter_layout = layout_mapping[letter];
		for (size_t j = 0; j < letter_layout.second; ++j)
			res += letter_layout.first;
		if (buttons_layout[letter_layout.first].find(next_letter) != string::npos) res += " ";
	}
	char letter = str[str.size() - 1];
	if (!(letter >= 'a' && letter <= 'z' || letter == ' ')) throw std::invalid_argument("unexpected symbol in input string : " + string(1, letter));
	pair<char, size_t> letter_layout = layout_mapping[letter];
	for (size_t i = 0; i < letter_layout.second; ++i)
		res += letter_layout.first;
	return res;
}
