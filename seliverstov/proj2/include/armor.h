#ifndef armor_protector
#define armor_protector
#include "weapons.h"
enum class ArmorType
{
	SKIN,
	MAIL,
	PLATE
};

class Armor
{
public:
	double baseProt();
	double speedPenalty();
	double getDefModifier(const Weapon&) = 0;
protected:
	Armor(const Armor&) = delete;
	double baseProt_;
	double speedPenalty_;
};

class Mail
	:public Armor
{
public:
	Mail();
	double getDefModifier(const Weapon&);
};

class Plate
	:public Armor
{
public:
	Plate();
	double getDefModifier(const Weapon&);
};

class Skin
	:public Armor
{
public:
	Skin();
	double getDefModifier(const Weapon&);
};
#endif
