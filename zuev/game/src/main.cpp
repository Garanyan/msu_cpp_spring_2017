#include "include/person.h"

#include <iostream>
using namespace std;

int main()
{
	Knight knight(9, 7, 4, 8);
	Sword sword(7, 3, 7);
	Chain chain(8, 2);
	knight.drop_weapon();
	knight.drop_armor();
	knight.take_weapon(sword);
	knight.take_armor(chain);
	cout << knight.get_speed() << endl;
	cout << knight.get_weapon().get_attack() << endl;
	knight.drop_weapon();
	knight.drop_armor();
	return 0;
}
