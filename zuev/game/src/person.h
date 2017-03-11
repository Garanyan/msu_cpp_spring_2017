#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "weapon.h"
#include "armor.h"

class Person
{
	private:
		int power;
		int ability;
		int speed;
		int skill;
		Weapon weapon;
		Armor armor;
	public:
		Person() {}
		Person(int power, int ability, int speed, int skill)
		{
			this->power   = power;
			this->ability = ability;
			this->speed   = speed;
			this->skill   = skill;
			this->weapon  = Fist();
			this->armor   = Shirt();
		}
		Person(const Person& person) = delete;
		Person& operator=(const Person& person) = delete;
		Person(const Person&& person)
		{
			this->power = person.power;
			this->ability = person.ability;
			this->speed = person.speed;
			this->skill = person.skill;
			this->weapon = std::move(person.weapon);
			this->armor = std::move(person.armor);
		}
		Person& operator=(const Person&& person)
		{
			this->power = person.power;
			this->ability = person.ability;
			this->speed = person.speed;
			this->skill = person.skill;
			this->weapon = std::move(person.weapon);
			this->armor = std::move(person.armor);
			return *this;
		}
		virtual ~Person() {}

		int get_power();
		int get_ability();
		int get_speed();
		int get_skill();
		void take_weapon(Weapon &&weapon);
		void take_armor(Armor &&armor);
		void drop_weapon();
		void drop_armor();
		Weapon& get_weapon();
		Armor& get_armor();
};

class Peasant: public Person
{
	public:
		Peasant(int power, int ability, int speed, int skill):
			Person(power, ability, speed, skill) {}
};

class Archer: public Person
{
	public:
		Archer(int power, int ability, int speed, int skill):
			Person(power, ability, speed, skill) {}
};

class Knight: public Person
{
	public:
		Knight(int power, int ability, int speed, int skill):
			Person(power, ability, speed, skill) {}
};

#endif
