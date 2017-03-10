#include "armor.h"
#include "weapon.h"

class Character{
public:
	double strength;
	double endurance;
	double velocity;
	double posession_of_shovel;
	double posession_of_bow;
	double posession_of_hammer;
	double posession_of_sword;
	Weapon weapon;
	Armor armor;
	void PutOnArmor(Armor armor);
	void PutOnWeapon(Weapon weapon);
};

class Peasant : public Character{

};

class Knight : public Character{

};

class Archer : public Character{

};