#include "weapon.h"
#include "armor.h"

class Person
{
	private:
		int power;
		int ability;
		int speed;
		int skill;
		Weapon *weapon;
		Armor *armor;
	public:
		Person(int power, int ability, int speed, int skill)
		{
			this->power   = power;
			this->ability = ability;
			this->speed   = speed;
			this->skill   = skill;
			this->weapon  = nullptr;
			this->armor   = nullptr;
		}
		virtual ~Person()
		{
			weapon = nullptr;
			armor  = nullptr;
		}

		int get_power()
		{
			return this->power;
		}
		int get_ability()
		{
			return this->ability;
		}
		int get_speed()
		{
			return this->speed;
		}
		int get_skill()
		{
			return this->skill;
		}
		void take_weapon(Weapon &weapon)
		{
			this->weapon = &weapon;
			return;
		}
		void take_armor(Armor &armor)
		{
			this->armor = &armor;
			return;
		}
		void drop_weapon()
		{
			this->weapon = nullptr;
			return;
		}
		void drop_armor()
		{
			this->armor = nullptr;
			return;
		}
		Weapon& get_weapon()
		{
			return *(this->weapon);
		}
		Armor& get_armor()
		{
			return *(this->armor);
		}
};

class Peasant: public Person
{
	public:
		Peasant(int power, int ability, int speed, int skill):
			Person(power, ability, speed, skill)
		{
		}
};

class Archer: public Person
{
	public:
		Archer(int power, int ability, int speed, int skill):
			Person(power, ability, speed, skill)
		{
		}
};

class Knight: public Person
{
	public:
		Knight(int power, int ability, int speed, int skill):
			Person(power, ability, speed, skill)
		{
		}
};
