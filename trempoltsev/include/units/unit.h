#pragma once

#include "traits.h"

namespace Arena
{
    class Armor;
    class Weapon;

    class Unit
    {
    public:
        Unit();
        virtual ~Unit() = 0;

        Unit(const Unit& copied) = delete;
        Unit& operator=(const Unit& copied) = delete;

        void wearArmor(Armor&& armor);
        void takeWeapon(Weapon&& weapon);

        virtual Points getDamageTo(const Unit& attacked) const;

    private:
        Armor&& armor_;
        Weapon&& weapon_;
    };

    namespace Details
    {
        template <class UnitTraits>
        class UnitImpl
            : public Unit
        {
        public:
            explicit UnitImpl(const std::string& name)
                : name_(name)
            {
                static_assert(std::is_base_of<Details::UnitTraits, UnitTraits>::value, "Invalid traits");
            }

        private:
            const std::string name_;
        };
    }
}
