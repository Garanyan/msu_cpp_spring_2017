//
// Created by ochaton on 2/25/17.
//
#include "stdafx.h"

std::vector<std::string> solve(std::vector<std::string> & data) {
    std::vector<std::string> result;
    std::vector<char> dict = { 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w' };
    for (auto word : data) {
        std::string res = "";
        char prev_ch = 0;
        for (auto ch : word) {
            if (ch == ' ') {
                if (prev_ch == '0') {
                    res += " ";
                }
                res += '0';
                prev_ch = '0';
                continue;
            }

            auto find_num = std::lower_bound(dict.begin(), dict.end(), ch);
            if (find_num == dict.end() or ch < *find_num) {
                --find_num;
            }

            char num = char('0' + 2 + std::distance(dict.begin(), find_num));
            std::string mult(uint(ch - *find_num) + 1, num);
            if (prev_ch == num) { // if previous is the same as current -> we need space
                res += " ";
            }

            prev_ch = num;
            res += mult;
        }
        result.push_back(res);
    }
    return result;
}
