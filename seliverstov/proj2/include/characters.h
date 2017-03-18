#ifndef characters_protector
#define characters_protector

#include "weapons.h"
#include "armor.h"

enum class PersonType
{
	PEASANT,
	ARCHER,
	KNIGHT,
	NINJA,
	SIZE
};

namespace CharactersStats
{
	const int peasantHP = 90;
	const int peasantStrength = 10;
	const int peasantStamina = 90;
	const int peasantMvSpeed = 100;

	const int archerHP = 75;
	const int archerStrength = 8;
	const int archerStamina = 65;
	const int archerMvSpeed = 70;

	const int knightHP = 130;
	const int knightStrength = 14;
	const int knightStamina = 130;
	const int knightMvSpeed = 110;

	const int ninjaHP = 100;
	const int ninjaStrength = 6;
	const int ninjaStamina = 200;
	const int ninjaMvSpeed = 140;
}

class Person
{
public:
	virtual Person(std::string) = 0;
	Weapon&& swapWeapon(Weapon&&);
	Armor&& swapArmor(Armor&&);
	void attack(Person&);
	void recvAttack(Person&);
	std::string nickname();
protected:
	std::unique_ptr<Weapon> weapon_;
	std::unique_ptr<Armor> armor_;
	std::string nickname_;
	bool dead_;
	int hitPoints_;
	int strength_;//reduses armor speed penalty
	int stamina_;
	int mvSpeed_;
	virtual double getWeaponModifier();//for current weapon
	bool operator==(std::string);//needed for a hashtable
};

/*
enum class WpnType
{
	FIST=0,
	SWORD=1,
	HAMMER=2,
	SHOVEL=3,
	BOW=4,
	GLAIVE=5,
	XBOW=6,
	BKNIFE=7,
	LSWORD=8,
	DAGGER=9
};
*/

class Peasant
	:public Person
{
public:
	Peasant(std::string);
private:
	static const float modifiers[];
	double getWeaponModifier();
};

class Archer
	:public Person
{
public:
	Archer(std::string);
private:
	static const float modifiers[];
	double getWeaponModifier();
};

class Knight
	:public Person
{
public:
	Knight(std::string);
private:
	static const float modifiers[];
	double getWeaponModifier();
};

class Ninja
	:public Person
{
public:
	Ninja(std::string);
private:
	static const float modifiers[];
	double getWeaponModifier();
}
#endif
