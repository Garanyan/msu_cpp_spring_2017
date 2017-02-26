#include <iostream>
using std::cin;
using std::cout;

#include "translater.hpp"

int main(int argc, char* argv[])
{
    TextOnNineTranslater t;
    t.translateStream(cin, cout);

    return 0;
}
