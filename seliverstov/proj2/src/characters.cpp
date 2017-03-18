#include "characters.h"

const float Peasant::modifiers[] = {5.0, 0.5, 0.6, 1.5, 0.1, 0.4, 0, 1.5, 0.2, 0.5};
const float Archer::modifiers[] = {1.0, 0.9, 0.4, 0.7, 1.5, 0.7, 1.5, 0.4, 0.3, 1.0};
const float Knight::modifiers[] = {1.0, 1.2, 1.2, 0.6, 0.4, 1.2, 0.2, 0.4, 1.0, 0.8};
const float Ninja::modifiers[] = {2.0, 1.0, 0.7, 0.4, 1.0, 0.8, 0.8, 0.7, 0.5, 1.5};

bool Person::operator==(std::string nickname)
{
	return nickname_ == nickname;
}

std::string Person::nickname()
{
	return nickname_;
}

Weapon&& Person::swapWeapon(Weapon&& moved)
{
	Weapon&& result = std::move(weapon_);
	weapon_ = std::move(moved);
	return result;
}

Armor&& Person::swapArmor(Armor&& moved)
{
	Armor&& result = std::move(armor_);
	armor_ = std::move(moved);
	return result;
}

double Peasant::getWeaponModifier()
{
	return modifiers[weapon_->type()];
}

Peasant::Peasant(const std::string& nickname):
	weapon_(new Fist),
	armor_(new Armor),
	nickname_(nickname),
	dead_(false),
	hitPoints_(CharactersStats::peasantHP),
	strength_(CharactersStats::peasantStrength),
	stamina_(CharactersStats::peasantStamina),
	mvSpeed_(CharactersStats::peasantMvSpeed)
	{}

double Knight::getWeaponModifier()
{
	return modifiers[weapon_->type()];
}

Knight::Knight(const std::string& nickname):
	weapon_(new Fist),
	armor_(new Armor),
	nickname_(nickname),
	dead_(false),
	hitPoints_(CharactersStats::knightHP),
	strength_(CharactersStats::knightStrength),
	stamina_(CharactersStats::knightStamina),
	mvSpeed_(CharactersStats::knightMvSpeed)
	{}

double Archer::getWeaponModifier()
{
	return modifiers[weapon_->type()];
}

Archer::Archer(const std::string& nickname):
	weapon_(new Fist),
	armor_(new Armor),
	nickname_(nickname),
	dead_(false),
	hitPoints_(CharactersStats::archerHP),
	strength_(CharactersStats::archerStrength),
	stamina_(CharactersStats::archerStamina),
	mvSpeed_(CharactersStats::archerMvSpeed)
	{}

double Ninja::getWeaponModifier()
{
	return modifiers[weapon_->type()];
}

Ninja::Ninja(const std::string& nickname):
	weapon_(new Fist),
	armor_(new Armor),
	nickname_(nickname),
	dead_(false),
	hitPoints_(CharactersStats::ninjaHP),
	strength_(CharactersStats::ninjaStrength),
	stamina_(CharactersStats::ninjaStamina),
	mvSpeed_(CharactersStats::ninjaMvSpeed)
	{}

