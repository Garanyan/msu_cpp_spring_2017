#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include "translater.hpp"

int main(int argc, char* argv[])
{
    TextOnNineTranslater t;

    int n_iterations;
    cin >> n_iterations;
    cin.ignore();
    for (int i = 0; i < n_iterations; i++) {
        string tmp;
        getline(cin, tmp);
        t.translateString(tmp, tmp);
        cout << "Case #" << i+1 << ": " << tmp << endl;
    }

    return 0;
}
