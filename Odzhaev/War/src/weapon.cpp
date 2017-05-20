#include "../include/weapon.h"

#include "stdafx.h"

//Weapon
Weapon::Weapon(Weapon&& movied)
{
	weaponPower_=movied.weaponPower_;
	weaponName_=movied.weaponName_;
	movied.weaponPower_=0;
	movied.weaponName_="boo";
}
Weapon& Weapon::operator=(Weapon&& movied)
{
	weaponPower_=movied.weaponPower_;
	weaponName_=movied.weaponName_;
	movied.weaponPower_=0;
	movied.weaponName_="boo";

	return *this;
}

const std::string Weapon::getName()
{
	return weaponName_;
}

Points Weapon::getPower() const
{
	return weaponPower_;
}


//Fists
Fists::Fists(const std::string& name): Weapon(name)
{
	weaponPower_ = FISTS_POWER;
}
WeaponType Fists::getType() const
{
	return WeaponType::Blunt;
}

//Hoe
Hoe::Hoe(const std::string& name): Weapon(name)
{
	weaponPower_ = HOE_POWER;
}
WeaponType Hoe::getType() const
{
	return WeaponType::Slashing;
}

//Sword
Sword::Sword(const std::string& name): Weapon(name)
{
	weaponPower_ = SWORD_POWER;
}
WeaponType Sword::getType() const
{
	return WeaponType::Slashing;
}

//Bow
Bow::Bow(const std::string& name): Weapon(name)
{
	weaponPower_ = BOW_POWER;
}
WeaponType Bow::getType() const
{
	return WeaponType::Piercing;
}

