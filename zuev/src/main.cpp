#include "stdafx.h"
#include "T9_translator.h"
using namespace std;

int main(int argc, char* argv[])
{
	T9_translator t;
	int n;
	string s;
	getline(cin, s);
	n = stoi(s);
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		try
		{
			cout << "Case #" << i+1 << ": " << t.translate(s) << endl;
		}
		catch (...)
		{
			cerr << "Undefiened error" << endl;
			return EXIT_FAILURE;
		}
	}
	return 0;
}
