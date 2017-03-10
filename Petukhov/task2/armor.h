#include "weapon.h"

class Armor{
public:
	double protection;
	double v_penalty;
	double count_protection(Weapon weapon);
	double subtract_velocity();
};

class Corslet : public Armor{

}

class Chain : public Armor{

}