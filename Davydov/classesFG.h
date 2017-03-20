#pragma once
// classes declaration
class NPC
{
public:
	int[3] SEV; // basic param
	int[4] skill; // how good with weapons; shovel, sword, bow, hammer
	bool weapon_is_eq; 
	bool armor_is_eq;
	virtual eq_weapon() = 0;
	virtual eq_armor() = 0;
	NPC();
	virtual ~NPC() {};
};

class Peasant : public NPC
{
public:
	Peasant()
	{
		SEV[0] = 4;
		SEV[1] = 3;
		SEV[2] = 3;
		
		skill[0] = 40;
		skill[1] = 20;
		skill[2] = 1;
		skill[3] = 20;

		weapon_is_eq = false;
		armor_is_eq = false;
	}
	// releqase eq_...
	~Peasant() {};

};

class Archer : public NPC
{
public:
	Archer() 
	{
		SEV[0] = 3;
		SEV[1] = 5;
		SEV[2] = 5;

		skill[0] = 20;
		skill[1] = 30;
		skill[2] = 80;
		skill[3] = 10;

		weapon_is_eq = false;
		armor_is_eq = false;
	}
	// release eq_...
	~Archer() {};

};

// release class Knight

class Weapon
{
public:
	enum weapon_type { shovel, sword, bow, hammer };
	penetration[4][2]
		Weapon(int w_t)
	{
		switch(w_t)
		case 0:
			penetration = 5;
			break;
		case 1:
			penetration = 15;
			break;
		case 2:
			penetration = 80;
			break;
		case 3:
			penetration = 30;
	}
};