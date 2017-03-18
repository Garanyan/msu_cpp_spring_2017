#include "person.h"

#include <iostream>
using namespace std;

int main()
{
	Knight knight(9, 7, 4, 8);
//	Sword sword(7, 3, 7);
//	Chain chain(8, 2);
	knight.take_weapon(Sword(7, 3, 7));
	knight.take_armor(Chain(8, 2));
	cout << knight.get_speed() << endl;
	cout << knight.get_weapon().get_attack() << endl;
	knight.drop_weapon();
	knight.drop_armor();
	return 0;
}
