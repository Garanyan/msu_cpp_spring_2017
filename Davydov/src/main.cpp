#include "stdafx.h"
#include <string>
#include <iostream>

using namespase std;
int main(int argc, char* argv[])
{
	string str;
	getline(cin, str);
	cout << transform(str) << endl;
	return 0;
}
