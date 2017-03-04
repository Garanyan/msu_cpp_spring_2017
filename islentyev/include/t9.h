#ifndef ISLENTYEV_T9_H
#define ISLENTYEV_T9_H

class T9
{
private:
    struct CharSequence
    {
        char Symbol;
        int Times;
    };
    std::map<char, CharSequence> dict;
public:
    T9();
    std::string spell(const std::string& text);
};

#endif //ISLENTYEV_T9_H