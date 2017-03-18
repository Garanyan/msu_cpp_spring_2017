#pragma once

#include "weapon.h"

namespace Arena
{
    class Fists
        : public Details::WeaponImpl<Details::FistsTraits>
    {
    public:
        ~Fists() override;
    };
}
