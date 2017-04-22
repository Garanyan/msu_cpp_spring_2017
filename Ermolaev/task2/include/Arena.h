#pragma once

#include "Person.h"
#include "stdafx.h"

// Arena
class Arena
{
public:
    Arena();
    std::unique_ptr<Person> fight(std::unique_ptr<Person>&& first, std::unique_ptr<Person>&& second);
    void addToFighters(std::unique_ptr<Person>&& person);
    std::unique_ptr<Person> fightsNet();

private:
    std::vector<std::unique_ptr<Person>>* fighters_;
    std::vector<std::unique_ptr<Person>>* winners_;
    bool isPowerOfTwo(int x) const;
};

