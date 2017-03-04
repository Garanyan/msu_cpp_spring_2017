//#include "stdafx.h"
#include "convert.h"
#include <iostream>
#include <string>

int main()
{
    Converter c(std::cin);
    std::string s;
    int n;
    std::getline(std::cin, s);
    n = std::stoi(s);
    for(int i = 1; i <= n; ++i)
    {
        c.convertNextLine(s);
        std::cout << "Case #" << i << ": " << s << std::endl;
    }
    return 0;
}
