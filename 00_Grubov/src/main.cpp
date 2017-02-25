#include "stdafx.h"
#include "Task.h"

int main(int argc, char* argv[])
{
    std::vector<std::string> input;
    int num; std::cin >> num;
    for (std::string line; (std::cin >> line) && num; --num) {
        input.push_back(line);
    }
    auto output = solve(input);
    for (auto line : output) {
        std::cout << "Case #" << num++ << ": " << line << std::endl;
    }
    return 0;
}
