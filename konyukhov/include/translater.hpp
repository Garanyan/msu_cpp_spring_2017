#include <string>
#include <tuple>
#include <map>

#ifndef __TextOnNineTranslater__
#define __TextOnNineTranslater__

#define BUFFER_LENGTH 128

class TextOnNineTranslater {
    char last_number { '\0' };
    char ibuffer[BUFFER_LENGTH];
    char obuffer[5 * BUFFER_LENGTH];

    static bool is_init;
    static std::map< char, std::pair<char, int> > keypad;
public:
    TextOnNineTranslater();

    void translateStream(std::istream & in, std::ostream & out);
    void translateString(std::string & dst, const std::string & src);
    std::string translateString(const std::string & src);

private:
    char * translateChar(char * dst, char target);
    void translateBuffer();
};

#endif
