#include "../include/armor.h"

#include "stdafx.h"

Armor::Armor(Armor&& movied)
{
	armorStamina_ = movied.armorStamina_;
	armorName_ = movied.armorName_;
}
Armor& Armor::operator=(Armor&& movied)
{
	armorStamina_ = movied.armorStamina_;
	armorName_ = movied.armorName_;
	return *this;
}

std::string Armor::getName() const
{	
	return armorName_;
}
Points Armor::getProtection() const
{
	return armorStamina_;
}


void Armor::changeStamina(const Points& armorWear)
{
	armorStamina_ = armorWear*armorStamina_;
}
