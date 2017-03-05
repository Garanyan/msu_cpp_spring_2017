//
//  buttons.cpp
//  Ovsepyan
//
//  Created by Эрик on 04.03.17.
//
//
#include "stdafx.h"
#include "buttons.hpp"

using namespace std;

std::string Nokia::convert(string text) {
    char previous = 0;
    string result = "";
    char last = text[text.length() - 1];
    while(isspace(last)){
        text.pop_back();
        last = text[text.length() - 1];
    }
    char first_alpha = 0;
    for (int i=0; i < text.length(); i++){
        if (!first_alpha){
            if (isspace(text[i])) continue;
            else first_alpha = 1;
        }
        
        string print;
        switch(text[i]){
            case 'a': print = "2"; break;
            case 'b': print = "22"; break;
            case 'c': print = "222"; break;
            case 'd': print = "3"; break;
            case 'e': print = "33"; break;
            case 'f': print = "333"; break;
            case 'g': print = "4"; break;
            case 'h': print = "44"; break;
            case 'i': print = "444"; break;
            case 'j': print = "5"; break;
            case 'k': print = "55"; break;
            case 'l': print = "555"; break;
            case 'm': print = "6"; break;
            case 'n': print = "66"; break;
            case 'o': print = "666"; break;
            case 'p': print = "7"; break;
            case 'q': print = "77"; break;
            case 'r': print = "777"; break;
            case 's': print = "7777"; break;
            case 't': print = "8"; break;
            case 'u': print = "88"; break;
            case 'v': print = "888"; break;
            case 'w': print = "9"; break;
            case 'x': print = "99"; break;
            case 'y': print = "999"; break;
            case 'z': print = "9999"; break;
            case ' ': print = "0"; break;
            default: throw std::invalid_argument("Bad simbol" + std::string(1, text[i]));
        }
        if (previous == print[0]) {
            result+=" ";
        }
        result+=print;
        previous = print[0];
    }
    return result;
}
