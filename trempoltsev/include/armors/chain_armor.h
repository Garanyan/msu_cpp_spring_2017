#pragma once

#include "armor.h"

namespace Arena
{
    class ChainArmor
        : public Details::ArmorImpl<Details::ChainArmorTraits>
    {
    public:
        ~ChainArmor() override;
    };
}
