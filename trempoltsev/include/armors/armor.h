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

        Armor(Armor&& movied) = default;
        Armor& operator=(Armor&& movied) = default;
    };

    namespace Details
    {
        template <class ArmorTraits>
        class ArmorImpl
            : public Armor
        {
        public:
            ArmorImpl()
            {
                static_assert(std::is_base_of<Details::ArmorTraits, ArmorTraits>::value, "Invalid traits");
            }
        };
    }
}
