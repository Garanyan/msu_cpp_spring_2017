#include "Barack.h"

// Barack
std::unique_ptr<Person> Barack::callPerson(const std::string& name)
{
    auto it = units_.find(name);
    if (it == units_.end())
        return nullptr;

    auto unit = std::move(it->second);
    units_.erase(it);
    return unit;
}
void Barack::addRandomPerson(const std::string& name)
{
    srand(std::clock());
    int r = std::rand() % 3;
    switch (r)
    {
        case 0: createPerson<Peasant>(name); break;
        case 1: createPerson<Knight>(name); break;
        case 2: createPerson<Archer>(name); break;
    }
}
template <class T>
void Barack::createPerson(const std::string& name)
{
    units_.emplace(name, std::unique_ptr<T>(new T(name)));
}
void Barack::deletePerson(const std::string& name)
{
    units_.erase(units_.find(name));
}
std::unique_ptr<Person> Barack::callRandPerson()
{
    auto it = units_.begin();
    if(it == units_.end())
        return nullptr;
    auto unit = std::move(it->second);
    units_.erase(it);
    return unit;
}
