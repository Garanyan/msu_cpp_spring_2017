#include "stdafx.h"

using namespace std;

struct key_def {
    char key;
    char repeat;
    
    key_def(): key(0), repeat(0) {};
    key_def(char a, char b): key(a), repeat(b) {};
};

class T9_translator {
public:
    string translate(string s);
    key_def letter2digit(int c);
};
