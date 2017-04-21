#ifndef ARENA_H_INCLUDED
#define ARENA_H_INCLUDED
#include <map>
#include "../include/person.h"
class Barrack
{
    std::map<std::string, std::unique_ptr<Person>> units;

    Barrack(Barrack const &) = delete;
    Barrack & operator= (Barrack const &) = delete;

public:
    Barrack() = default;
    virtual ~Barrack() = default;
    std::unique_ptr<Person> getUnit(const std::string &);
    void addUnit(std::unique_ptr<Person>);
    Person & operator[] (const std::string &);
};

#endif // ARENA_H_INCLUDED
