#include "stdafx.h"

#include "../include/armors/without_armor.h"
#include "../include/weapons/fists.h"

#include "../include/units/unit.h"

Arena::Unit::Unit()
    : armor_(WithoutArmor())
    , weapon_(Fists())
{
}

Arena::Unit::~Unit()
{
}

void Arena::Unit::wearArmor(Armor&& armor)
{
    armor_ = std::move(armor);
}

void Arena::Unit::takeWeapon(Weapon&& weapon)
{
    weapon_ = std::move(weapon);
}

Arena::Points Arena::Unit::getDamageTo(const Unit& attacked) const
{
}
