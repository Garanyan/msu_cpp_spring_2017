#pragma once

#include "../arena_types.h"

#include "../armors/traits.h"
#include "../weapons/traits.h"

namespace Arena
{
    namespace Details
    {
        struct UnitTraits {};

        struct PeasantTraits : public UnitTraits
        {
            static constexpr Points armorSkill(Chains*)             { return 0.6; }
            static constexpr Points armorSkill(Plates*)             { return 0.2; }
            static constexpr Points armorSkill(Unarmored*)          { return 2.5; }

            static constexpr Points weaponSkill(BluntWeapon*)       { return 1.5; }
            static constexpr Points weaponSkill(Martial*)           { return 3.0; }
            static constexpr Points weaponSkill(Swords*)            { return 0.8; }
            static constexpr Points weaponSkill(Ranged*)            { return 0.5; }

            static constexpr Points Strength                        = 10;
        };

        struct ArcherTraits : public UnitTraits
        {
            static constexpr Points armorSkill(Chains*)             { return 2.0; }
            static constexpr Points armorSkill(Plates*)             { return 0.8; }
            static constexpr Points armorSkill(Unarmored*)          { return 1.0; }

            static constexpr Points weaponSkill(BluntWeapon*)       { return 1.0; }
            static constexpr Points weaponSkill(Martial*)           { return 1.5; }
            static constexpr Points weaponSkill(Swords*)            { return 2.0; }
            static constexpr Points weaponSkill(Ranged*)            { return 5.0; }

            static constexpr Points Strength                        = 15;
        };

        struct KnightTraits : public UnitTraits
        {
            static constexpr Points armorSkill(Chains*)             { return 2.0; }
            static constexpr Points armorSkill(Plates*)             { return 3.0; }
            static constexpr Points armorSkill(Unarmored*)          { return 1.0; }

            static constexpr Points weaponSkill(BluntWeapon*)       { return 2.0; }
            static constexpr Points weaponSkill(Martial*)           { return 1.0; }
            static constexpr Points weaponSkill(Swords*)            { return 5.0; }
            static constexpr Points weaponSkill(Ranged*)            { return 1.0; }

            static constexpr Points Strength                        = 10;
        };
    }

    template <class UnitTraits, class ArmorTraits>
    Points getArmorSkill()
    {
        return UnitTraits::armorSkill(static_cast<typename ArmorTraits::ArmorType*>(nullptr));
    }

    template <class UnitTraits, class WeaponTraits>
    Points getWeaponSkill()
    {
        return UnitTraits::weaponSkill(static_cast<typename WeaponTraits::WeaponType*>(nullptr));
    }
}
