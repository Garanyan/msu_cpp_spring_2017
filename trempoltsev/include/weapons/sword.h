#pragma once

#include "weapon.h"

namespace Arena
{
    class Sword
        : public Details::WeaponImpl<Details::SwordTraits>
    {
    public:
        ~Sword() override;
    };
}
