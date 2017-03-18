#pragma once

#include "weapon.h"

namespace Arena
{
    class Bow
        : public Details::WeaponImpl<Details::BowTraits>
    {
    public:
        ~Bow() override;
    };
}
