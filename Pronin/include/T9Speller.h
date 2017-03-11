# pragma once
# include "stdafx.h"
# include "ISpeller.h"
# include <string>
# include <map>

using std::string;
using std::map;
using std::pair;


static map<char, string> const default_buttons_layout = {
	{ '2', "abc" }, { '3', "def" },
	{ '4', "ghi" }, { '5', "jkl" }, { '6', "mno" },
	{ '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" },
	{ '0', " " }
};


/**
* @brief This class translates words to t9 notation
*/
class T9Speller: public ISpeller<string>
{
	map<char, string> buttons_layout;
	map<char, pair<char, size_t>> layout_mapping;
public:
	/**
	* @brief Constructor
	* @param buttons layout. If no layout set, uses default buttons layout
	* @return T9Speller object
	*/
	T9Speller(map<char, string> const & buttons_layout = default_buttons_layout);
	/**
	* @brief Destructor
	*/
	~T9Speller();
	/**
	* @brief Translate a text to t9 notation
	* @param str Text to translate. It contains only a-z and space characters
	* @return The text in T9 notation. It contains only digits and spaces
	* @throw std::invalid_argument If source text is empty
	* @throw std::invalid_argument If source text contains invalid characters
	*/
	string spell(string const &);
};
