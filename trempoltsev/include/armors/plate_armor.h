#pragma once

#include "armor.h"

namespace Arena
{
    class PlateArmor
        : public Details::ArmorImpl<Details::PlateArmorTraits>
    {
    public:
        ~PlateArmor() override;
    };
}
