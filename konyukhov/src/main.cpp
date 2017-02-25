#include "stdafx.h"

#include <iostream>
#include <map>
#include <tuple>
#include <string>
using std::string;

const std::map<string, int> keypad =
{
    {" ", 0},
    {"abc", 2},
    {"def", 3},
    {"ghi", 4},
    {"jkl", 5},
    {"mno", 6},
    {"pqrs", 7},
    {"tuv", 8},
    {"wxyz", 9}
};

// it returns (key number, position)
std::pair<int, int> letter_to_keypad(char ch) {
    string letters;
    int number;
    int position;

    for (auto & keypad_pair : keypad) {
        std::tie(letters, number) = keypad_pair;
        position = letters.find(ch);
        if (position >= 0) break;
    }
    return std::pair<int, int>(number, position);
}

class Foo {
    int prevNumber;
    int prevPosition;

    std::istream & input;
    std::ostream & output;

public:
    Foo(std::istream & in, std::ostream & out) :
        input(in) , output(out)
    {
        if (input)
            std::tie(prevNumber, prevPosition) = letter_to_keypad(input.get());
        else
            throw string("IO error");
    }

    void run() {
        int currNumber, currPosition;
        while (!input.eof()) {
            std::tie(currNumber, currPosition) = letter_to_keypad(input.get());
            print(prevNumber, prevPosition);
            if (currNumber == prevNumber) output.put(' ');

            prevNumber = currNumber;
            prevPosition = currPosition;
        }
        print(prevNumber, prevPosition);
        output << "\b";
    }

private:
    void print(int number, int position) {
        char ch = std::to_string(number)[0];
        for (int i = 0; i < position + 1; i++) {
            output.put(ch);
        }
    }
};

int main(int argc, char* argv[])
{
    auto f = Foo(std::cin, std::cout);
    f.run();
    return 0;
}
