#pragma once

#include "armor.h"

namespace Arena
{
    class WithoutArmor
        : public Details::ArmorImpl<Details::WithoutArmorTraits>
    {
    public:
        ~WithoutArmor() override;
    };
}
