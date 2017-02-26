#include "translater.hpp"

#include <iostream>
#include <map>
#include <tuple>
using std::tie;
using std::pair;

#include <sstream>
#include <string>
using std::string;

#include <cstring>

bool TextOnNineTranslater::is_init = false;
std::map< char, pair<char, int> > TextOnNineTranslater::keypad;

TextOnNineTranslater::TextOnNineTranslater() {
    if (is_init) return;

    char number;
    string letters;
    std::map<string, char> tmp_keypad = {
        {" ",    '0'}, {"abc",  '2'}, {"def",  '3'},
        {"ghi",  '4'}, {"jkl",  '5'}, {"mno",  '6'},
        {"pqrs", '7'}, {"tuv",  '8'}, {"wxyz", '9'}
    };

    for (auto & key_pair : tmp_keypad) {
        std::tie(letters, number);

        int counter = 1;
        for (char ch : letters)
            keypad[ch] = pair<char, int>(number, counter++);
    }
}

string TextOnNineTranslater::translateString(const string & src) {
    string dst;
    translateString(dst, src);
    return dst;
}

void TextOnNineTranslater::translateString(string & dst, const string & src) {
    std::istringstream input(src);
    std::ostringstream output;

    translateStream(input, output);
    dst = output.str();
}

void TextOnNineTranslater::translateStream(std::istream & in = std::cin, std::ostream & out = std::cout) {
    while (!in.eof() && in.peek() != '\n') {
        in.get(ibuffer, BUFFER_LENGTH);
        out << obuffer;
    }
    if (!in.eof()) in.get();
}

void TextOnNineTranslater::translateBuffer() {
    char * iptr = ibuffer;
    char * optr = obuffer;

    while (*iptr != '\0') {
        optr = translateChar(optr, *(iptr++));
    }
    *optr = '\0';
}

char * TextOnNineTranslater::translateChar(char * dst, char target) {
    char letter; int count;
    tie(letter, count) = keypad[target];

    if (letter == last_number) *(dst++) = ' ';
    last_number = letter;

    memset(dst, letter, count);
    return dst + count;
}
