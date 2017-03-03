#include "stdafx.h"
#include "translator.h"

int main(int argc, char* argv[])
{
	try {
		Translator t;
		int n;
		string s;
		getline(cin, s);
		n = stoi(s);
		for (int i = 0; i < n; i++)
		{
			getline(cin, s);
			cout << "Case #" << i+1 << ": " << t.translate(s) << endl;
		}
		return 0;
	}
	catch (...)
	{
		cout << "Error: wrong input!" << endl;
		return EXIT_FAILURE;
	}
}
