#pragma once

#include "Person.h"
#include "stdafx.h"

// Barack
class Barack
{
public:
    std::unique_ptr<Person> callPerson(const std::string& name);
    void addRandomPerson(const std::string& name);
    template <class T>
    void createPerson(const std::string& name);
    void deletePerson(const std::string& name);
    std::unique_ptr<Person> callRandPerson();
private:
    std::unordered_map<std::string, std::unique_ptr<Person>> units_;
};
