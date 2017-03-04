#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

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

string toString(int i)
{
    ostringstream oss;
    oss<< i;
    return oss.str();
}

string T9Spell::translate(string c){
	int pos;
	string cpos;
	string res = "";
	try{
		if(c.length() == 0){
			throw invalid_argument("Empty input");
		}
		for(int l = 0; l < c.length(); l++){
			if (c[l] != ' ' && (c[l] > 'z' || c[l] < 'a')){
				throw invalid_argument("There is a symbol in your input that is not on the keyboard.\nPlease use only english letters");
				break;
			}
			for(int i = 0; i < 10; i++){
				pos = keyboard[i].find(c[l]);
				if (pos == string::npos){
					continue;
				} else{
					cpos = toString(i);
					if(res.length() > 0 && res[res.length() - 1] == cpos[0])
						res += " ";
					while(pos >= 0){
						res += toString(i);
						pos--;
					}
				}
			}
		}
	}
	catch(invalid_argument err){
		cout << string(err.what());
		throw err;
		return "";
	}
	return res;
}

