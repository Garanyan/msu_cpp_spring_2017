#include <iostream>
#include "weapon.h"
#include "armor.h"
using namespace std;

class character {
public:
	int CharType;
	int strength;	// сила
	int stamina;	// высносливость
	int speed;		// скорость
	int weaponSkill = 1;	// умение владеть оружием
	int weaponType;
	int armorType;

	character(int CharType1, int strength1, int stamina1, int speed1) {	//конструктор базового класса
		CharType = CharType1;
		strength = strength1;
		speed = speed1;
		stamina = stamina1;
	}

	void takeWeapon(weapon someWeapon) {
		cout << "took weapon" << someWeapon.weaponType << "\n";
		weaponType = someWeapon.weaponType;
		weaponSkill = CharWeaponTable(CharType, someWeapon.weaponType);
	}

	void takeArmor(armor someArmor) {
		cout << "took Armor" << someArmor.armorType << "\n";
		armorType = someArmor.armorType;
		speed = int(speed * someArmor.speedPenalty);
	}

	int CharWeaponTable(int CharType1, int weaponType1) {
		int i = CharType1;
		int j = weaponType1;
		int table[3][4];

		table[0][0] = 100;		table[0][1] = 20;		table[0][2] = 20;		table[0][3] = 20;
		table[1][0] = 20;		table[1][1] = 100;		table[1][2] = 20;		table[1][3] = 20;
		table[2][0] = 20;		table[2][1] = 20;		table[2][2] = 100;		table[2][3] = 20;
		return table[i][j];
	}
};

class farmer : public character {
public:
	farmer(int CharType1 = 0, int strength1 = 50, int stamina1 = 80, int speed1 = 80) :character(CharType1, strength1, stamina1, speed1) {};
};

class knight : public character {
public:
	knight(int CharType1 = 1, int strength1 = 100, int stamina1 = 80, int speed1 = 50) :character(CharType1, strength1, stamina1, speed1) {};
};

class archer : public character {
public:
	archer(int CharType1 = 2, int strength1 = 50, int stamina1 = 100, int speed1 = 80) :character(CharType1, strength1, stamina1, speed1) {};
};