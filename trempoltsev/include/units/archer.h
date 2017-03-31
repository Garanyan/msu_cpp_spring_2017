#pragma once

#include "unit.h"

namespace Arena
{
    class Archer
        : Details::UnitImpl<Details::ArcherTraits>
    {
    public:
        explicit Archer(const std::string& name);
        ~Archer() override;
    };
}
