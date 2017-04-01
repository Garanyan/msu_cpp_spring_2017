// polly.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <memory>
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

int damage(const character& red, const character& blue) {

	int redCharProp = red.speed * red.stamina * red.strength * red.weaponSkill;
	int blueCharProp = blue.speed * blue.stamina * blue.strength * blue.weaponSkill;
	return abs(100 * (double(redCharProp) / double(blueCharProp))*weaponArmorTable(red.weaponType, blue.armorType));

};

int main(int argc, char* argv[]) {

	armor chain(0, 50, 0.7);	// кольчуга
	armor lats(1, 70, 0.5);		// латы

	sword Petr;
	bow Sergey;
	kazarma dom;

	unique_ptr<knight> John = dom.allocate_knight(); // объ€вление объекта
	John->takeWeapon(move(Petr));
	John->takeArmor(move(lats));
	cout << "John.weaponSkill "<< John->weaponSkill << "\n";

	unique_ptr<archer> Jack = dom.allocate_archer();
	Jack->takeWeapon(move(Sergey));
	Jack->takeArmor(move(chain));

	cout << "damage(John, Jack) is " << damage(*John, *Jack) << "\n";

	system("pause");

	return 0;
}