#include "stdafx.h"
#include "t9translator.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

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

int main(int argc, char* argv[])
{
	T9Spell translator;
	int N;
	string input;
	bool move_on = false;
	while(!move_on){
		cout << "Type in the number of cases please:\n";
		cin >> N;
		if (N > 100 || N < 1){
			cout << "Sorry, the number of cases should be bigger than 1 and less than 100. Try again!\n";
		} else{
			move_on = true;
		}
	}
	getchar();
	for(int i = 0; i < N; i++){
		try{
			getline(cin, input);
			cout << "Case #" << i+1 << ": " << translator.translate(input) << '\n';
		}
		catch(invalid_argument err){
			cout << '\n';
			continue;
		}
	}
	system("pause");
    return 0;
}