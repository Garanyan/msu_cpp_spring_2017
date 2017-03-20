#ifndef armor_protector
#define armor_protector
#include "weapons.h"
enum class ArmorType
{
	SKIN,
	MAIL,
	PLATE,
	LEATHER,
	SCALE,
	SIZE
};

namespace ArmorStats
{
	const double mailProt = 0.25;
	const double mailSpdMod = 0.7;
	
	const double plateProt = 0.4;
	const double plateSpdMod = 0.55;

	const double skinProt = 0.05;
	const double skinSpdMod = 1;

	const double leatherProt = 0.15;
	const double leatherSpdMod = 0.85;

	const double scaleProt = 0.45;
	const double scaleSpdMod = 0.5;
}

class Armor
{
public:
	double baseProt();
	double speedModifier();
	virtual double getDef(WpnType) = 0;
protected:
	Armor(const Armor&) = delete;
	Armor& operator= (const Armor&) = delete;
	double baseProt_;
	double speedModifier_;
};

/*
enum class WpnType
{
	FIST = 0,
	SWORD = 1,
	HAMMER = 2,
	SHOVEL = 3,
	BOW = 4,
	GLAIVE = 5,
	XBOW = 6,
	BKNIFE = 7,
	LSWORD = 8,
	DAGGER = 9
};
*/

class Mail
	:public Armor
{
	static const double modifiers[];

public:
	Mail();
	double getDef(int);
};

class Plate
	:public Armor
{
	static const double modifiers[];

public:
	Plate();
	double getDef(int);
};

class Skin
	:public Armor
{
	static const double modifiers[];

public:
	Skin();
	double getDef(int);
};

class Leather
	:public Armor
{
	static const double modifiers[];

public:
	Leather();
	double getDef(int);
}

class Scale
	:public Armor
{
	static const double modifiers[];

public:
	Scale();
	double getDef(int)
};

#endif
