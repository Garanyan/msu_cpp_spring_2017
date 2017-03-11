#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>

class Armor
{
	private:
		int defence;
		int speed_penalty;
	public:
		Armor() {}
		Armor(int defence, int speed_penalty)
		{
			this->defence = defence;
			this->speed_penalty = speed_penalty;
		}
		Armor(const Armor& armor) = delete;
		Armor& operator=(const Armor& armor) = delete;
		Armor(const Armor&& armor)
		{
			this->defence = armor.defence;
			this->speed_penalty = armor.speed_penalty;
		}
		Armor& operator=(const Armor&& armor)
		{
			this->defence = armor.defence;
			this->speed_penalty = armor.speed_penalty;
			return *this;
		}
		virtual ~Armor() {}

		int get_defence();
		int get_speed_penalty();
};

class Shirt: public Armor
{
	public:
		Shirt(): Armor(1, 10) {}
};

class Chain: public Armor
{
	public:
		Chain(int defence, int speed_penalty):
			Armor(defence, speed_penalty) {}
};

class Simple_Armor: public Armor
{
	public:
		Simple_Armor(int defence, int speed_penalty):
			Armor(defence, speed_penalty) {}
};

#endif
