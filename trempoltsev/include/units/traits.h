#pragma once

#include <arena_types.h>

#include <armors/traits.h>
#include <weapons/traits.h>

namespace Arena
{
    namespace Details
    {
        struct UnitTraits {};

        struct PeasantTraits : public UnitTraits
        {
            template <class ArmorType> constexpr Points armorSkill() const;
            template <class WeaponType> constexpr Points weaponSkill() const;

            template <> constexpr Points armorSkill<ChainArmorTraits>() const   { return 1; }
            template <> constexpr Points armorSkill<PlateArmorTraits>() const   { return 1; }

            template <> constexpr Points weaponSkill<FistsTraits>() const       { return 1; }
            template <> constexpr Points weaponSkill<ShovelTraits>() const      { return 3; }
            template <> constexpr Points weaponSkill<BowTraits>() const         { return 1; }
            template <> constexpr Points weaponSkill<SwordTraits>() const       { return 1; }
            template <> constexpr Points weaponSkill<HammerTraits>() const      { return 1; }

            static constexpr Points Strength                                    = 10;
        };

        struct ArcherTraits : public UnitTraits
        {
            template <class ArmorType> constexpr Points armorSkill() const;
            template <class WeaponType> constexpr Points weaponSkill() const;

            template <> constexpr Points armorSkill<ChainArmorTraits>() const   { return 1; }
            template <> constexpr Points armorSkill<PlateArmorTraits>() const   { return 1; }

            template <> constexpr Points weaponSkill<FistsTraits>() const       { return 1; }
            template <> constexpr Points weaponSkill<ShovelTraits>() const      { return 3; }
            template <> constexpr Points weaponSkill<BowTraits>() const         { return 1; }
            template <> constexpr Points weaponSkill<SwordTraits>() const       { return 1; }
            template <> constexpr Points weaponSkill<HammerTraits>() const      { return 1; }

            static constexpr Points Strength                                    = 15;
        };

        struct KnightTraits : public UnitTraits
        {
            template <class ArmorType> constexpr Points armorSkill() const;
            template <class WeaponType> constexpr Points weaponSkill() const;

            template <> constexpr Points armorSkill<ChainArmorTraits>() const   { return 1; }
            template <> constexpr Points armorSkill<PlateArmorTraits>() const   { return 1; }

            template <> constexpr Points weaponSkill<FistsTraits>() const       { return 1; }
            template <> constexpr Points weaponSkill<ShovelTraits>() const      { return 3; }
            template <> constexpr Points weaponSkill<BowTraits>() const         { return 1; }
            template <> constexpr Points weaponSkill<SwordTraits>() const       { return 1; }
            template <> constexpr Points weaponSkill<HammerTraits>() const      { return 1; }

            static constexpr Points Strength                                    = 20;
        };
    }
}
