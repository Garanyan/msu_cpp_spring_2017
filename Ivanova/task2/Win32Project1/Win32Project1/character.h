#pragma once

using namespace std;

class character {
public:

	character(int charType, int strength, int stamina, int speed) 
		: charType(charType), strength(strength), stamina(stamina), speed(speed) {}
	virtual ~character() {}

	int charType;
	int strength;	// сила
	int stamina;	// высносливость
	int speed;		// скорость
	int weaponSkill = 1;	// умение владеть оружием
	int weaponType;
	int armorType;

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

	farmer(): character(0, 50, 70, 100) {}

	virtual ~farmer() {}

	farmer(const farmer& copied) = delete;
	farmer& operator = (const farmer& copied) = delete;

	farmer(farmer&& x) = default;
	farmer& operator = (farmer&& x) = default;

};

class knight : public character {
public:

	knight(): character(1, 30, 80, 60) {}

	virtual ~knight() {}

	knight(const knight& copied) = delete;
	knight& operator = (const knight& copied) = delete;

	knight(knight&& x) = default;
	knight& operator = (knight&& x) = default;
	
};

class archer : public character {
public:

	archer(): character(2, 50, 40, 70) {}
	virtual ~archer() {}

	archer(const archer& copied) = delete;
	archer& operator = (const archer& copied) = delete;

	archer(archer&& x) = default;
	archer& operator = (archer&& x) = default;

};