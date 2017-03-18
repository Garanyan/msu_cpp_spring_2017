#pragma once

#include "../arena_types.h"
#include "../weapons/damage_type.h"

namespace Arena
{
    namespace Details
    {
        struct BodyTraits
        {
            template <class DamageType> static constexpr Points protection();

            template <> static constexpr Points protection<Piercing>()  { return 0; }
            template <> static constexpr Points protection<Slashing>()  { return 0; }
            template <> static constexpr Points protection<Blunt>()     { return 0; }

            static constexpr Factor PenaltyToSpeed                      = 1.0;
        };

        struct ChainArmorTraits
        {
            template <class DamageType> static constexpr Points protection();

            template <> static constexpr Points protection<Piercing>()  { return 30; }
            template <> static constexpr Points protection<Slashing>()  { return 50; }
            template <> static constexpr Points protection<Blunt>()     { return 10; }

            static constexpr Factor PenaltyToSpeed                      = 1.2;
        };

        struct PlateArmorTraits
        {
            template <class DamageType> static constexpr Points protection();

            template <> static constexpr Points protection<Piercing>()  { return 60; }
            template <> static constexpr Points protection<Slashing>()  { return 80; }
            template <> static constexpr Points protection<Blunt>()     { return 40; }

            static constexpr Factor PenaltyToSpeed                      = 1.5;
        };
    }
}
