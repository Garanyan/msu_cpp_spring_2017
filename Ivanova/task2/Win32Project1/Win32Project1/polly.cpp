// polly.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
using namespace std;

double weaponArmorTable(int redWeaponType, int blueArmorType) {
	double table[4][2];
	int i = redWeaponType;
	int j = blueArmorType;

	table[0][0] = 0.5;		table[0][1] = 0.6;
	table[1][0] = 0.2;		table[1][1] = 1;
	table[2][0] = 1;		table[2][1] = 0.2;
	table[3][0] = 0.8;		table[3][1] = 0.7;

	return table[i][j];
}

int damage(character&& red, character&& blue) {
	int redCharProp = red.speed * red.stamina * red.strength * red.weaponSkill;
	int blueCharProp = blue.speed * blue.stamina * blue.strength * blue.weaponSkill;
	return abs(100 * (double(redCharProp) / double(blueCharProp))*weaponArmorTable(red.weaponType, blue.armorType));
};

int main(int argc, char* argv[]) {

	weapon shovel(0, 20, 50, 20);	//лопата
	weapon sword(1, 100, 50, 20);	// меч
	weapon bow(2, 50, 80, 100);		// лук
	weapon hammer(3, 100, 50, 20);	// молот

	armor chain(0, 50, 0.7);	// кольчуга
	armor lats(1, 70, 0.5);		// латы

	knight John; // объ€вление объекта
	John.takeWeapon(move(sword));
	John.takeArmor(move(lats));
	cout << "John.weaponSkill "<< John.weaponSkill << "\n";

	archer Jack;
	Jack.takeWeapon(move(bow));
	Jack.takeArmor(move(chain));

	cout << "damage(John, Jack) is " << damage(move(John), move(Jack)) << "\n";

	system("pause");

	return 0;
}