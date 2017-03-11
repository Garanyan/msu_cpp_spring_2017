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
	baseDmg_(WeaponStats::ShovelDmg),
	baseSpd_(WeaponStats::ShovelSpd),
	baseRng_(WeaponStats::ShovelRng)
	{}

Shovel::~Shovel()
	{}

ButcherKnife::ButcherKnife():
	baseDmg_(WeaponStats::BKnifeDmg),
	baseSpd_(WeaponStats::BKnifeSpd),
	baseRng_(WeaponStats::BKnifeRng)
	{}

ButcherKnife::~ButcherKnife()
	{}

Dagger::Dagger():
	baseDmg_(WeaponStats::DaggerDmg),
	baseSpd_(WeaponStats::DaggerSpd),
	baseRng_(WeaponStats::DaggerRng)
	{}

Dagger::~Dagger()
	{}

Glaive::Glaive():
	baseDmg_(WeaponStats::GlaiveDmg),
	baseSpd_(WeaponStats::GlaiveSpd),
	baseRng_(WeaponStats::GlaiveRng)
	{}

Glaive::~Glaive()
	{}

Bow::Bow():
	baseDmg_(WeaponStats::BowDmg),
	baseSpd_(WeaponStats::BowSpd),
	baseRng_(WeaponStats::BowRng)
	{}

Bow::~Bow()
	{}

Crossbow::Crossbow():
	baseDmg_(WeaponStats::XbowDmg),
	baseSpd_(WeaponStats::XbowSpd),
	baseRng_(WeaponStats::XbowRng)
	{}

Crossbow::~Crossbow()
	{}

Hammer::Hammer():
	baseDmg_(WeaponStats::HammerDmg),
	baseSpd_(WeaponStats::HammerSpd),
	baseRng_(WeaponStats::HammerRng)
	{}

Hammer::~Hammer()
	{}

Sword::Sword():
	baseDmg_(WeaponStats::SwordDmg),
	baseSpd_(WeaponStats::SwordSpd),
	baseRng_(WeaponStats::SwordRng)
	{}

Sword::~Sword()
	{}

Longsword::Longsword():
	baseDmg_(WeaponStats::LswordDmg),
	baseSpd_(WeaponStats::LswordSpd),
	baseRng_(WeaponStats::LswordRng)
	{}

Longsword::~Longsword()
	{}

Fist::Fist():
	baseDmg_(WeaponStats::FistDmg),
	baseSpd_(WeaponStats::FistSpd),
	baseRng_(WeaponStats::FistRng)
	{}

Fist::~Fist()
	{}

