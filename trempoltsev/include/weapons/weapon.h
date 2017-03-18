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
    };

    namespace Details
    {
        template <class WeaponTraits>
        class WeaponImpl
            : public Weapon
        {
        };
    }
}
