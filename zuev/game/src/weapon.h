#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
	private:
		int speed;
		int distance;
		int attack;
	public:
		Weapon() {}
		Weapon(int speed, int distance, int attack)
		{
			this->speed    = speed;
			this->distance = distance;
			this->attack   = attack;
		}
		Weapon(const Weapon& weapon) = delete;
		Weapon& operator=(const Weapon& weapon) = delete;
		Weapon(const Weapon&& weapon)
		{
			this->speed = weapon.speed;
			this->distance = weapon.distance;
			this->attack = weapon.attack;
		}
		Weapon& operator=(const Weapon&& weapon)
		{
			this->speed = weapon.speed;
			this->distance = weapon.distance;
			this->attack = weapon.attack;
			return *this;
		}
		virtual ~Weapon() {}

		int get_speed();
		int get_distance();
		int get_attack();
};

class Fist: public Weapon
{
	public:
		Fist(): Weapon(8, 2, 1) {}
};

class Shovel: public Weapon
{
	public:
		Shovel(int speed, int distance, int attack):
			Weapon(speed, distance, attack) {}
};

class Sword: public Weapon
{
	public:
		Sword(int speed, int distance, int attack):
			Weapon(speed, distance, attack) {}
};

class Bow: public Weapon
{
	public:
		Bow(int speed, int distance, int attack):
			Weapon(speed, distance, attack) {}
};

class Hammer: public Weapon
{
	public:
		Hammer(int speed, int distance, int attack):
			Weapon(speed, distance, attack) {}
};

#endif
