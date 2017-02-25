#include <iostream>
#include <string>

#include "stdafx.h"
#include "libt9.h"

using namespace std;

int main(int argc, char* argv[])
{
    int N;
    cin >> N;


    string s;
    getline(cin, s); //reading '\n' after N
    
    for (int i=0; i<N; i++) {
       getline(cin, s);
       cout << "Case #" << i+1 << ": " << convert(s) << endl;
    }
        
    return 0;
}
