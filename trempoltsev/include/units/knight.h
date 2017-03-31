#pragma once

#include "unit.h"

namespace Arena
{
    class Knight
        : Details::UnitImpl<Details::KnightTraits>
    {
    public:
        explicit Knight(const std::string& name);
        ~Knight() override;
    };
}
