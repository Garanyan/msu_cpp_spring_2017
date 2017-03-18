#include "armor.h"
Armor::baseProt()
{
	return baseProt_;
}

Armor::speedPenalty()
{
	return speedPenalty_;
}

const double Mail::modifiers[] =
	{0.2, 0.5, 0.1, 0.5, 0, 0.5, 0, 0.5, 0.3, 0.2};

const double Plate::modifiers[] =
	{0.8, 0.4, 0.3, 0.7, 0.8, 0.5, 0.5, 0.7, 0.5, 0.1};

const double Leather::modifiers[] =
	{0, 0.3, 0.1, 0.4, 0.5, 0.4, 0.3, 0.3, 0.2, 0.1};

const double Scale::modifiers[] =
	{0.8, 0.4, 0.5, 0.7, 0.8, 0.5, 0.35, 0.5, 0.4, 0.5};

const double Skin::modifiers[] =
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

Mail::Mail():
	baseProt_(ArmorStats::mailProt),
	speedPenalty(ArmorStats::mailSpdMod)
	{}

double Skin::getDef(int wpnType)
{
	if (wpnType < (sizeof(modifiers) / sizeof(double)))
		return (1 - baseProt_) * (1 - modifiers[wpnType]) + baseProt_;
	else
		throw std::invalid_value(
			std::string("Error: out of bounds in Armor::getDef(")
			+ to_string(wpnType) + ")\n");
}

double Mail::getDef(int wpnType)
{
	if (wpnType < (sizeof(modifiers) / sizeof(double)))
		return (1 - baseProt_) * (1 - modifiers[wpnType]) + baseProt_;
	else
		throw std::invalid_value(
			std::string("Error: out of bounds in Armor::getDef(")
			+ to_string(wpnType) + ")\n");
}

double Plate::getDef(int wpnType)
{
	if (wpnType < (sizeof(modifiers) / sizeof(double)))
		return (1 - baseProt_) * (1 - modifiers[wpnType]) + baseProt_;
	else
		throw std::invalid_value(
			std::string("Error: out of bounds in Armor::getDef(")
			+ to_string(wpnType) + ")\n");
}

double Leather::getDef(int wpnType)
{
	if (wpnType < (sizeof(modifiers) / sizeof(double)))
		return (1 - baseProt_) * (1 - modifiers[wpnType]) + baseProt_;
	else
		throw std::invalid_value(
			std::string("Error: out of bounds in Armor::getDef(")
			+ to_string(wpnType) + ")\n");
}

double Scale::getDef(int wpnType)
{
	if (wpnType < (sizeof(modifiers) / sizeof(double)))
		return (1 - baseProt_) * (1 - modifiers[wpnType]) + baseProt_;
	else
		throw std::invalid_value(
			std::string("Error: out of bounds in Armor::getDef(")
			+ to_string(wpnType) + ")\n");
}

Plate::Plate():
	baseProt_(ArmorStats::plateProt),
	speedPenalty(ArmorStats::plateSpdMod)
	{}

Skin::Skin():
	baseProt_(ArmorStats::skinProt),
	speedPenalty(ArmorStats::skinSpdMod)
	{}

Leather::Leather():
	baseProt_(ArmorStats::leatherProt),
	speedPenalty(ArmorStats::leatherSpdMod)
	{}

Scale::Scale():
	baseProt_(ArmorStats::scaleProt),
	speedPenalty(ArmorStats::scaleSpdMod)
	{}

