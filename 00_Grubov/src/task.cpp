//
// Created by ochaton on 2/25/17.
//
#include "stdafx.h"

std::vector<std::string> solve(std::vector<std::string> & data) {
    std::vector<std::string> result;
    for (auto word : data) {
        std::string res = "";
        for (auto ch : word) {
            if (res.length() != 0) {
                res += " ";
            }
            if (ch <= 'c') {
                std::string mult("2", uint('c' - ch));
                res += mult;
            } else if (ch <= 'f') {
                std::string mult("3", uint('f' - ch));
                res += mult;
            } else if (ch <= 'i') {
                std::string mult("4", uint('i' - ch));
                res += mult;
            } else if (ch <= 'l') {
                std::string mult("5", uint('l' - ch));
                res += mult;
            } else if (ch <= 'o') {
                std::string mult("6", uint('o' - ch));
                res += mult;
            } else if (ch <= 's') {
                std::string mult("7", uint('s' - ch));
                res += mult;
            } else if (ch <= 'v') {
                std::string mult("8", uint('v' - ch));
                res += mult;
            } else if (ch <= 'z') {
                std::string mult("9", uint('z' - ch));
                res += mult;
            }
        }
        result.push_back(res);
    }
    return result;
}
