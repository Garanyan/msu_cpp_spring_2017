#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include "t9.h"

std::string t9_translate(const std::string& text)
{
    int prev;
    int ok = 0;
    std::string res;
    std::vector<char>::iterator pos;
    ptrdiff_t count;
    std::vector <std:: vector<char> > symbols = {{' '},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    
    int n = text.length();
 //   try{
        if(n==0) throw std::invalid_argument(std::string("empty string"));
        for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < 9; ++j)
                {
                    pos = find(std::begin(symbols[j]), std::end(symbols[j]), text[i]);
                    if(pos!= std::end(symbols[j]))
                    {
                        ok = 1;
                        if (i>0 && j == prev) res+=" ";
                        count  = pos - begin(symbols[j]);
                        prev = j;
                        for(int k=0; k <= count; ++k)
                            if(j == 0) res+= ('0' + j);
                            else res+=('0' + j + 1);
                    }
                }
                if(ok==0) throw std::invalid_argument(std::string("invalid car"));
   //         }
    }
  /*  catch(int i)
    {
        cout << "Wrong symbol on position: "<<i+1;
    }*/
    return res;
}
