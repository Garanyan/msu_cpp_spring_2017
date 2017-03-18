#pragma once

#include "../arena_types.h"
#include "damage_type.h"

namespace Arena
{
    namespace Details
    {
        struct FistsTraits
        {
            using DamageType                        = Blunt;
            static constexpr Points damage          = 5;
            static constexpr SecondsToAttack speed  = 1;
        };

        struct ShovelTraits
        {
            using DamageType                        = Slashing;
            static constexpr Points damage          = 30;
            static constexpr SecondsToAttack speed  = 2;
        };

        struct BowTraits
        {
            using DamageType                        = Piercing;
            static constexpr Points damage          = 50;
            static constexpr SecondsToAttack speed  = 4;
        };

        struct SwordTraits
        {
            using DamageType                        = Slashing;
            static constexpr Points damage          = 70;
            static constexpr SecondsToAttack speed  = 2;
        };

        struct HammerTraits
        {
            using DamageType                        = Blunt;
            static constexpr Points damage          = 100;
            static constexpr SecondsToAttack speed  = 4;
        };
    }
}
