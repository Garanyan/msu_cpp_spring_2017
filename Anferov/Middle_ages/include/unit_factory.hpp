#include <memory>
#include "character.hpp"

class unitFactory
{
public:
    virtual std::unique_ptr<character> getUnit() = 0;
};

class romanUnitFactory: public unitFactory
{
public:
    std::unique_ptr<character> getUnit() override;
};

class barbarianUnitFactory: public unitFactory
{
public:
    std::unique_ptr<character> getUnit() override;
};
