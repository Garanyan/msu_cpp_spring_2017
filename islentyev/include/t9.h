#ifndef ISLENTYEV_T9_H
#define ISLENTYEV_T9_H

class T9
{
private:
    struct SymbolSequence
    {
        char Symbol;
        unsigned Times;
    };
    std::map<char, SymbolSequence> dictionary;
public:
    T9();
    std::string spell(const std::string &text);
};

#endif //ISLENTYEV_T9_H
