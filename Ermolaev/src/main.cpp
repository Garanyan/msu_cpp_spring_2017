#include "stdafx.h"
#include "T9.h"

using namespace std;


int main(int argc, char* argv[])
{
    T9 t;
    int n;
    string s;

    getline(cin, s);
	n = stoi(s);
    
    vector<string> v(n);
    for(int i = 0; i < n; ++i){
        getline(cin, v[i]);
    }
    for(int i = 0; i < n; ++i){
        cout << "Case #" << i+1 << ": " << t.translate(v[i]) << endl;
    }
    return 0;
}
