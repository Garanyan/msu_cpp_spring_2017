#include "weapons.h"

Weapon::baseDmg()
{
	return baseDmg_;
}

Weapon::baseSpd()
{
	return baseSpd_;
}

Weapon::baseRange()
{
	return baseRange_;
}

Shovel::Shovel():
	type_(WpnType::SHOVEL),
	baseDmg_(WeaponStats::shovelDmg),
	baseSpd_(WeaponStats::shovelSpd),
	baseRng_(WeaponStats::shovelRng)
	{}

Shovel::~Shovel()
	{}

ButcherKnife::ButcherKnife():
	type_(WpnType::BKNIFE),
	baseDmg_(WeaponStats::bKnifeDmg),
	baseSpd_(WeaponStats::bKnifeSpd),
	baseRng_(WeaponStats::bKnifeRng)
	{}

ButcherKnife::~ButcherKnife()
	{}

Dagger::Dagger():
	type_(WpnType::DAGGER),
	baseDmg_(WeaponStats::daggerDmg),
	baseSpd_(WeaponStats::daggerSpd),
	baseRng_(WeaponStats::daggerRng)
	{}

Dagger::~Dagger()
	{}

Glaive::Glaive():
	type_(WpnType::GLAIVE),
	baseDmg_(WeaponStats::glaiveDmg),
	baseSpd_(WeaponStats::glaiveSpd),
	baseRng_(WeaponStats::glaiveRng)
	{}

Glaive::~Glaive()
	{}

Bow::Bow():
	type_(WpnType::BOW),
	baseDmg_(WeaponStats::bowDmg),
	baseSpd_(WeaponStats::bowSpd),
	baseRng_(WeaponStats::bowRng)
	{}

Bow::~Bow()
	{}

Crossbow::Crossbow():
	type_(WpnType::XBOW),
	baseDmg_(WeaponStats::xbowDmg),
	baseSpd_(WeaponStats::xbowSpd),
	baseRng_(WeaponStats::xbowRng)
	{}

Crossbow::~Crossbow()
	{}

Hammer::Hammer():
	type_(WpnType::HAMMER),
	baseDmg_(WeaponStats::hammerDmg),
	baseSpd_(WeaponStats::hammerSpd),
	baseRng_(WeaponStats::hammerRng)
	{}

Hammer::~Hammer()
	{}

Sword::Sword():
	type_(WpnType::SWORD),
	baseDmg_(WeaponStats::swordDmg),
	baseSpd_(WeaponStats::swordSpd),
	baseRng_(WeaponStats::swordRng)
	{}

Sword::~Sword()
	{}

Longsword::Longsword():
	type_(WpnType::LSWORD),
	baseDmg_(WeaponStats::lswordDmg),
	baseSpd_(WeaponStats::lswordSpd),
	baseRng_(WeaponStats::lswordRng)
	{}

Longsword::~Longsword()
	{}

Fist::Fist():
	type_(WpnType::FIST),
	baseDmg_(WeaponStats::fistDmg),
	baseSpd_(WeaponStats::fistSpd),
	baseRng_(WeaponStats::fistRng)
	{}

Fist::~Fist()
	{}

