#pragma once

#include "weapon.h"

namespace Arena
{
    class Hammer
        : public Details::WeaponImpl<Details::HammerTraits>
    {
    public:
        ~Hammer() override;
    };
}
