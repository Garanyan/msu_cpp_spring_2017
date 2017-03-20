#pragma once

using namespace std;

class character {
public:

	character() {}
	virtual ~character() {}

	int charType;
	int strength;	// сила
	int stamina;	// высносливость
	int speed;		// скорость
	int weaponSkill = 1;	// умение владеть оружием
	int weaponType;
	int armorType;

	character(int charType, int strength, int stamina, int speed)
		: charType(charType), strength(strength), stamina(stamina), speed(speed) {}


	void takeWeapon(weapon&& someWeapon) {
		cout << "took weapon" << someWeapon.weaponType << "\n";
		weaponType = someWeapon.weaponType;
		weaponSkill = CharWeaponTable(charType, someWeapon.weaponType);
	}

	void takeArmor(armor&& someArmor) {
		cout << "took Armor" << someArmor.armorType << "\n";
		armorType = someArmor.armorType;
		speed = int(speed * someArmor.speedPenalty);
	}


	//character(character&& movied) = default;


	int CharWeaponTable(int charType, int weaponType) {
		int i = charType;
		int j = weaponType;
		int table[3][4];

		table[0][0] = 100;		table[0][1] = 20;		table[0][2] = 20;		table[0][3] = 20;
		table[1][0] = 20;		table[1][1] = 100;		table[1][2] = 20;		table[1][3] = 20;
		table[2][0] = 20;		table[2][1] = 20;		table[2][2] = 100;		table[2][3] = 20;

		return table[i][j];
	}

};

class farmer : public character {
public:

	farmer() {}
	virtual ~farmer() {}

	farmer(const farmer& copied) = delete;
	farmer& operator = (const farmer& copied) = delete;

	farmer(farmer&& x) : character(move(x)),
		charType(move(x.charType)), 
		strength(move(x.strength)),
		stamina(move(x.stamina)),
		speed(move(x.speed)) {};

	farmer& operator = (farmer&& x) 
	{
		character::operator=(move(x));
		charType = (move(x.charType));
		strength = (move(x.strength));
		stamina = (move(x.stamina));
		speed = (move(x.speed));

		return *this;
	};

	int charType = 0;
	int strength = 50; 
	int stamina = 80;
	int speed = 80;

};

class knight : public character {
public:

	knight() {}
	virtual ~knight() {}

	knight(const knight& copied) = delete;
	knight& operator = (const knight& copied) = delete;

	knight(knight&& x) : character(move(x)),
		charType(move(x.charType)),
		strength(move(x.strength)),
		stamina(move(x.stamina)),
		speed(move(x.speed)) {};

	knight& operator = (knight&& x)
	{
		character::operator=(move(x));
		charType = (move(x.charType));
		strength = (move(x.strength));
		stamina = (move(x.stamina));
		speed = (move(x.speed));

		return *this;
	};

	int charType = 1;
	int strength = 100;
	int stamina = 80; 
	int speed = 50;
	
};

class archer : public character {
public:

	archer() {}
	virtual ~archer() {}

	archer(const archer& copied) = delete;
	archer& operator = (const archer& copied) = delete;

	archer(archer&& x) : character(move(x)),
		charType(move(x.charType)),
		strength(move(x.strength)),
		stamina(move(x.stamina)),
		speed(move(x.speed)) {};

	archer& operator = (archer&& x)
	{
		character::operator=(move(x));
		charType = (move(x.charType));
		strength = (move(x.strength));
		stamina = (move(x.stamina));
		speed = (move(x.speed));

		return *this;
	};

	int charType = 2; 
	int strength = 50; 
	int stamina = 100; 
	int speed = 80;

};