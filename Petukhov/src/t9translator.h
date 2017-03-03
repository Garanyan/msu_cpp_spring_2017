#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>

class T9Spell{
	map<int, string> keyboard;
public:
	T9Spell(){
		keyboard.insert(pair<int, string>(2, "abc"));
		keyboard.insert(pair<int, string>(3, "def"));
		keyboard.insert(pair<int, string>(4, "ghi"));
		keyboard.insert(pair<int, string>(5, "jkl"));
		keyboard.insert(pair<int, string>(6, "mno"));
		keyboard.insert(pair<int, string>(7, "pqrs"));
		keyboard.insert(pair<int, string>(8, "tuv"));
		keyboard.insert(pair<int, string>(9, "wxyz"));
		keyboard.insert(pair<int, string>(0, " +"));
	}
	string translate(string c);
};

string toString(int i);