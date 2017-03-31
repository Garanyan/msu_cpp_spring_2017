#pragma once

#include "../arena_types.h"
#include "damage_type.h"
#include "weapon_type.h"

namespace Arena
{
    namespace Details
    {
        struct WeaponTraits {};

        struct FistsTraits : public WeaponTraits
        {
            using DamageType                        = Blunt;
            using WeaponType                        = Martial;

            static constexpr Points damage          = 5;
            static constexpr SecondsToAttack speed  = 1;
        };

        struct ShovelTraits : public WeaponTraits
        {
            using DamageType                        = Blunt;
            using WeaponType                        = BluntWeapon;

            static constexpr Points damage          = 30;
            static constexpr SecondsToAttack speed  = 2;
        };

        struct BowTraits : public WeaponTraits
        {
            using DamageType                        = Piercing;
            using WeaponType                        = Ranged;

            static constexpr Points damage          = 50;
            static constexpr SecondsToAttack speed  = 4;
        };

        struct SwordTraits : public WeaponTraits
        {
            using DamageType                        = Slashing;
            using WeaponType                        = Swords;

            static constexpr Points damage          = 70;
            static constexpr SecondsToAttack speed  = 2;
        };

        struct HammerTraits : public WeaponTraits
        {
            using DamageType                        = Blunt;
            using WeaponType                        = BluntWeapon;

            static constexpr Points damage          = 100;
            static constexpr SecondsToAttack speed  = 4;
        };
    }
}
