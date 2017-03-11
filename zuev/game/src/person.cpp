#include "person.h"

int Person::get_power()
{
	return this->power;
}
int Person::get_ability()
{
	return this->ability;
}
int Person::get_speed()
{
	return this->speed;
}
int Person::get_skill()
{
	return this->skill;
}
void Person::take_weapon(Weapon &&weapon)
{
//	this->drop_weapon();
	this->weapon = std::move(weapon);
	return;
}
void Person::take_armor(Armor &&armor)
{
//	this->drop_armor();
	this->armor = std::move(armor);
	return;
}
void Person::drop_weapon()
{
	this->weapon = Fist();
	return;
}
void Person::drop_armor()
{
	this->armor = Shirt();
	return;
}
Weapon& Person::get_weapon()
{
	return this->weapon;
}
Armor& Person::get_armor()
{
	return this->armor;
}
