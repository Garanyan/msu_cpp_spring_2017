#pragma once

#include "weapon.h"

namespace Arena
{
    class Shovel
        : public Details::WeaponImpl<Details::ShovelTraits>
    {
    public:
        ~Shovel() override;
    };
}
