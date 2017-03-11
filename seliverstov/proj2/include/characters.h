#ifndef characters_protector
#define characters_protector

#include "weapons.h"
#include "armor.h"

enum class PersonType
{
	PEASANT,
	ARCHER,
	KNIGHT
};

class Person
{
public:
	Person(Weapon*, Armor*);
	void takeWeapon(Weapon&&);
	void takeArmor(Armor&&);
	void attack(Person&);
	void recvAttack(Person&);
protected:
	std::string nickname_;
	Weapon* weapon_;
	Armor* armor_;
	bool dead_;
	int hitPoints_;
	int strength_;
	int stamina_;
	int mvSpeed_;
	int baseWeaponMastery_;
	virtual int getWeaponMastery();//for current weapon
	bool operator==(std::string);//needed for adding this in an unordered set
};

class Peasant
	:public Person
{
public:
	Peasant(Weapon&&, Armor&&);
private:
	int getWeaponMastery();
};

class Archer
	:public Person
{
public:
	Archer(Weapon&&, Armor&&);
private:
	int getWeaponMastery();
};

class Knight
	:public Person
{
public:
	Knight(Weapon&&, Armor&&);
private:
	int getWeaponMastery();
};
#endif
