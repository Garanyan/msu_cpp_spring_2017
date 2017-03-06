#include "stdafx.h"
using namespace std;

class T9{
private:
	string convert(char c){
		switch (c){
			case 'a': return "2";
			case 'b': return "22";
			case 'c': return "222";
			case 'd': return "3";
			case 'e': return "33";
			case 'f': return "333";
			case 'g': return "4";
			case 'h': return "44";
			case 'i': return "444";
			case 'j': return "5";
			case 'k': return "55";
            case 'l': return "555";
			case 'm': return "6";
			case 'n': return "66";
			case 'o': return "666";
			case 'p': return "7";
			case 'q': return "77";
			case 'r': return "777";
			case 's': return "7777";
			case 't': return "8";
			case 'u': return "88";
			case 'v': return "888";
			case 'w': return "9";
			case 'x': return "99";
			case 'y': return "999";
			case 'z': return "9999";
			case ' ': return "0";
			default :
                      std::cerr << "invalid character " << c;
                      std::cerr << ": replacing it with '_'" << std::endl;
                      return "_";
		}
	}
public:
    string translate(string s){
		if (s.empty())
			throw invalid_argument(string("empty string"));
        string res = "", tmp;
        for(auto c: s){
            tmp = convert(c);
            if (res[res.size()-1] == tmp[0])
                res += ' ';
            res += tmp;
        }
        return res;
    }
};
