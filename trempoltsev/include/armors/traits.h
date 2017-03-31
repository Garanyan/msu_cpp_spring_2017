#pragma once

#include "../arena_types.h"
#include "../weapons/damage_type.h"
#include "armor_type.h"

namespace Arena
{
    namespace Details
    {
        struct ArmorTraits {};

        struct ChainArmorTraits : public ArmorTraits
        {
            using ArmorType = Chains;

            static constexpr Points protection(Piercing*)   { return 30; }
            static constexpr Points protection(Slashing*)   { return 50; }
            static constexpr Points protection(Blunt*)      { return 10; }

            static constexpr Factor PenaltyToSpeed          = 1.2;
        };

        struct PlateArmorTraits : public ArmorTraits
        {
            using ArmorType = Plates;

            static constexpr Points protection(Piercing*)   { return 60; }
            static constexpr Points protection(Slashing*)   { return 80; }
            static constexpr Points protection(Blunt*)      { return 40; }

            static constexpr Factor PenaltyToSpeed          = 1.5;
        };

        struct WithoutArmorTraits : public ArmorTraits
        {
            using ArmorType = Unarmored;

            static constexpr Points protection(Piercing*)   { return 0; }
            static constexpr Points protection(Slashing*)   { return 0; }
            static constexpr Points protection(Blunt*)      { return 0; }

            static constexpr Factor PenaltyToSpeed          = 1.0;
        };
    }

    template <class ArmorTraits, class WeaponTraits>
    Points getProtection()
    {
        return ArmorTraits::protection(static_cast<typename WeaponTraits::DamageType*>(nullptr));
    }
}
