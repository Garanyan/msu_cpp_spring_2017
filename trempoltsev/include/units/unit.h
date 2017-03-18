#pragma once

#include "traits.h"

namespace Arena
{
    class Unit
    {
        virtual ~Unit() = default;
    };

    namespace Details
    {
        template <class UnitTraits>
        class UnitImpl
            : public Unit
        {
        public:
            explicit UnitImpl(const std::string& name)
                : this->name(name)
            {
            }

        private:
            const std::string name;
        };
    }
}
