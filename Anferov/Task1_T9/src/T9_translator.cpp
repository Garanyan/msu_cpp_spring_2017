#include "stdafx.h"
#include "T9_translator.h"

using namespace std;

key_def T9_translator::letter2digit(int c) {
    static const char key[]    = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    static const char repeat[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    
    if (c == ' ') return key_def(0,1);
    
    if (c < 'a' || c > 'z') {
        throw "Unsupported symbol!";
    }
    
    int order = c - int('a');
    
    return key_def(key[order], repeat[order]);
};

string T9_translator::translate(string s) {
    char previous_key = 1;
    key_def current;
    stringstream result;
    
    for (char c: s) {
        current = letter2digit(c);
        if (previous_key == current.key) {
            result << ' ';
        }
        for (int i=0; i<current.repeat; i++) {
            result << char('0'+current.key);
        }
        previous_key = current.key;
    }
    
    return result.str();
};
