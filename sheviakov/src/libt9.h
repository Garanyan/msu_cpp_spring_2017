#ifndef LIBT9
#define LIBT9

#include <string>

int f () {
    return 15;
}

const char * char_code(char c) {
    return
    (c == 'a') ? "2"    :
    (c == 'b') ? "22"   :
    (c == 'c') ? "222"  :
    (c == 'd') ? "3"    :
    (c == 'e') ? "33"   :
    (c == 'f') ? "333"  :
    (c == 'g') ? "4"    :
    (c == 'h') ? "44"   :
    (c == 'i') ? "444"  :
    (c == 'j') ? "5"    :
    (c == 'k') ? "55"   :
    (c == 'l') ? "555"  :
    (c == 'm') ? "6"    :
    (c == 'n') ? "66"   :
    (c == 'o') ? "666"  :
    (c == 'p') ? "7"    :
    (c == 'q') ? "77"   :
    (c == 'r') ? "777"  :
    (c == 's') ? "7777" :
    (c == 't') ? "8"    :
    (c == 'u') ? "88"   :
    (c == 'v') ? "888"  :
    (c == 'w') ? "9"    :
    (c == 'x') ? "99"   :
    (c == 'y') ? "999"  :
    (c == 'z') ? "9999" :
    (c == ' ') ? "0"    : "" ;
}

std::string convert(std::string s) {
    std::string msg = "";
    for (int i=0; i<s.length(); i++) {
        char curr = s[i];
	const char *code = char_code(curr);
        if (msg.back() == code[0]) msg += " ";
	msg += code;
    }
    return msg;
}

#endif //LIBT9i
