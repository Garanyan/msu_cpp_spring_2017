#pragma once

#include <arena_types.h>

#include <armors/traits.h>
#include <weapons/traits.h>

namespace Arena
{
    namespace Details
    {
        struct PeasantTraits
        {
            template <class ArmorType> constexpr Points armorSkill() const;
            template <class WeaponType> constexpr Points weaponSkill() const;

            template <> constexpr Points armorSkill<BodyTraits>() const         { return 1; }
            template <> constexpr Points armorSkill<ChainArmorTraits>() const   { return 1; }
            template <> constexpr Points armorSkill<PlateArmorTraits>() const   { return 1; }

            template <> constexpr Points weaponSkill<FistTraits>() const        { return 1; }
            template <> constexpr Points weaponSkill<ShovelTraits>() const      { return 3; }
            template <> constexpr Points weaponSkill<BowTraits>() const         { return 1; }
            template <> constexpr Points weaponSkill<SwordTraits>() const       { return 1; }
            template <> constexpr Points weaponSkill<HummerTraits>() const      { return 1; }

            static const Points Strength                                        = 10;
        };

        struct ArcherTraits
        {
            template <class ArmorType> constexpr Points armorSkill() const;
            template <class WeaponType> constexpr Points weaponSkill() const;

            template <> constexpr Points armorSkill<BodyTraits>() const         { return 1; }
            template <> constexpr Points armorSkill<ChainArmorTraits>() const   { return 1; }
            template <> constexpr Points armorSkill<PlateArmorTraits>() const   { return 1; }

            template <> constexpr Points weaponSkill<FistTraits>() const        { return 1; }
            template <> constexpr Points weaponSkill<ShovelTraits>() const      { return 3; }
            template <> constexpr Points weaponSkill<BowTraits>() const         { return 1; }
            template <> constexpr Points weaponSkill<SwordTraits>() const       { return 1; }
            template <> constexpr Points weaponSkill<HummerTraits>() const      { return 1; }

            static const Points Strength                                        = 10;
        };

        struct KnightTraits
        {
            template <class ArmorType> constexpr Points armorSkill() const;
            template <class WeaponType> constexpr Points weaponSkill() const;

            template <> constexpr Points armorSkill<BodyTraits>() const         { return 1; }
            template <> constexpr Points armorSkill<ChainArmorTraits>() const   { return 1; }
            template <> constexpr Points armorSkill<PlateArmorTraits>() const   { return 1; }

            template <> constexpr Points weaponSkill<FistTraits>() const        { return 1; }
            template <> constexpr Points weaponSkill<ShovelTraits>() const      { return 3; }
            template <> constexpr Points weaponSkill<BowTraits>() const         { return 1; }
            template <> constexpr Points weaponSkill<SwordTraits>() const       { return 1; }
            template <> constexpr Points weaponSkill<HummerTraits>() const      { return 1; }

            static const Points Strength                                        = 10;
        };
    }
}
