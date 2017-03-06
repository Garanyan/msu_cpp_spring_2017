#include "stdafx.h"
#include "buttons.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    int count = 0;
    string input;
    while( count == 0 ){
        try {
            getline(cin, input);
            if (input == "q") return EXIT_SUCCESS;
            count = stoi(input);
        }
        catch(invalid_argument) {
            cout<<"Type words count or 'q' to exit\n";
            continue;
        }
    }
    Nokia n;
    for (int i = 0; i < count; ++i) {
        
        while(1) {
            try {
                getline(cin,input);
                cout << "case #" << i + 1 << ": ";
                cout <<  n.convert(input) << endl;
                break;
            }
            catch (std::invalid_argument){
                cerr<< "Error! Try again\n";
            }
        }
    }
	return EXIT_SUCCESS;
}
