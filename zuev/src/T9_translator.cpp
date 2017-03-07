#include "T9_translator.h"

string T9_translator::convert(char c)
{
	switch (c)
	{
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
		default:
			cout << endl << "'" << c << "' is a wrong symbol";
			cout << ", it was replaced by '_'" << endl;
			return "_";
	}
}

string T9_translator::translate(string s)
{
	if (s == "") return "";
	string res = convert(s[0]);
	char prev = res[0];
	for (int i = 1; i < s.size(); i++)
	{
		string tmp = convert(s[i]);
		if ((prev != '_') && (prev == tmp[0])) res += ' ';
		res += tmp;
		prev = tmp[0];
	}
	return res;
}
