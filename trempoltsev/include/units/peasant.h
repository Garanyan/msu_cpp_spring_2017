#pragma once

#include "unit.h"

namespace Arena
{
    class Peasant
        : Details::UnitImpl<Details::PeasantTraits>
    {
    public:
        explicit Peasant(const std::string& name);
        ~Peasant() override;
    };
}
