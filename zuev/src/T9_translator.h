#ifndef T9_TRANSLATOR_H
#define T9_TRANSLATOR_H
#include <iostream>
using namespace std;

class T9_translator
{
	private:
		string convert(char c);
	public:
		string translate(string s);
};

#endif
