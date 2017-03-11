#include "armor.h"

class Weapon{
public:
	double penetration_corslet;
	double penetration_chains;
	double velocity;
	double range;
	double count_penetration(Armor armor);
};

class Shovel : public Weapon{

};

class Bow : public Weapon{

};

class Hammer : public Weapon{

};

class Sword : public Weapon{

};