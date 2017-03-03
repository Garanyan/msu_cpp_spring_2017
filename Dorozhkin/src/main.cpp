#include "stdafx.h"
#include "diler.h"

int main(int argc, char const *argv[]) {
    int n; // count of tests
    std::string s;
    std::vector<std::string> out;
    
    std::cin >> n;
    std::getline(std::cin, s);
    for (auto i = 0; i < n; i++) {
        std::getline(std::cin, s);
        out.push_back("Case #" + std::to_string(i + 1) + dile(s));
    }
    
    for (auto o : out) {
        std::cout << o << std::endl;
    }
    return 0;
}
