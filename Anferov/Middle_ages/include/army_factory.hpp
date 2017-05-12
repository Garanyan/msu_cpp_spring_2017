#include <memory>
#include "storage.hpp"
#include "unit_factory.hpp"

class army_factory
{
    std::unique_ptr<unitFactory> ufp;
public:
    army_factory(std::unique_ptr<unitFactory>);
    std::unique_ptr<army> getArmy(int);
};

class roman_army_factory: public army_factory
{
public:
    roman_army_factory();
};

class barbarian_army_factory: public army_factory
{
public:
    barbarian_army_factory();
};
