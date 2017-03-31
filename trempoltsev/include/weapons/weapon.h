#pragma once

#include "traits.h"

namespace Arena
{
    class Weapon
    {
    public:
        Weapon() = default;
        virtual ~Weapon() = 0;

        Weapon(const Weapon& copied) = delete;
        Weapon& operator=(const Weapon& copied) = delete;

        Weapon(Weapon&& movied) = default;
        Weapon& operator=(Weapon&& movied) = default;
    };

    namespace Details
    {
        template <class WeaponTraits>
        class WeaponImpl
            : public Weapon
        {
        public:
            WeaponImpl()
            {
                static_assert(std::is_base_of<Details::WeaponTraits, WeaponTraits>::value, "Invalid traits");
            }
        };
    }
}
