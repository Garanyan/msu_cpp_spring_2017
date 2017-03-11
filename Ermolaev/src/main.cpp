#include "stdafx.h"
#include "T9.h"

using namespace std;

int main(int argc, char* argv[])
{
    try
    {
        T9 t;
        int n;
        string s;

        getline(cin, s);
        n = stoi(s);
        if(n <= 0)
            throw std::invalid_argument(string("invalid value N"));
        
        vector<string> text(n);
        for(int i = 0; i < n; ++i)
            getline(cin, text[i]);
        
        for(int i = 0; i < n; ++i)
            cout << "Case #" << i+1 << ": " << t.translate(text[i]) << endl;
        
        return 0;
    }
    catch (const invalid_argument& error)
    {
        cerr << error.what() << endl;
        return -1;
    }
    catch(...)
    {
        cerr << "Unexpected error" << endl;
        return -1;
    }
}
