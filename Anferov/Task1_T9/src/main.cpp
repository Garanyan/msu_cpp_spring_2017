#include "stdafx.h"
#include "T9_translator.h"

using namespace std;

int main(int argc, char* argv[]) {
    int n;
    string text;
    T9_translator t9;
    
    try {
        cin >> n;
        getline(cin, text);
    } catch (...) {
        cerr << "Incorrect number of cases!" << endl;
        return -1;
    }
    
    try {
        for (int i=1; i<=n; i++) {
            getline(cin, text);
            cout << "Case #" << i << ": " << t9.translate(text) << endl;
        }
    } catch (const char * msg) {
        cout << "ERROR!!! " << msg << endl;
        return -1;
    }
    
    return 0;
}
