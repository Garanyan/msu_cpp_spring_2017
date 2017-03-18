#pragma once

#include "traits.h"

namespace Arena
{
    class Armor
    {
    public:
        Armor() = default;
        virtual ~Armor() = 0;

        Armor(const Armor& copied) = delete;
        Armor& operator=(const Armor& copied) = delete;
    };

    namespace Details
    {
        template <class ArmorTraits>
        class ArmorImpl
            : public Armor
        {
        };
    }
}
