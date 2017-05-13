#pragma once

//class Armor;
//class Weapon;
#include "..//Medieval_Game//Armor.cpp"
#include "..//Medieval_Game//Weapons.cpp"


struct NPC
{
private:
	NPC(const NPC& copied) = delete;
	NPC& operator=(const NPC& copied) = delete;

public:
//	int SEV[3]; // basic param
//	int skill[5]; // how good with weapons; shovel, sword, bow, hammer
	Point health;
	std::string NPC_name;
	const std::string& getName() const;
	
	
	std::unique_ptr<Weapon> weapon = std::unique_ptr<Fists>(new Fists());
	std::unique_ptr<Armor> armor = std::unique_ptr<WithoutArmor>(new WithoutArmor());

	const /*std::string&*/ void eq_weapon(std::unique_ptr<Weapon> && weapon);

	const void /*std::string&*/ eq_armor(std::unique_ptr<Armor> && armor);

	Point getHealth() {
		return health;
	}
/*
	void attack(NPC& attacked) {

		const auto protection = attacked.armor->getProtection(weapon->getDamageType());
		const auto damage = weapon->getDamage();

		const auto points = protection - damage;
		if (!points)
			attacked.health += points;


	}
*/


	//	Armor armor;
	//	Weapon weapon;
	//	std::string name;

	NPC() {};
	virtual ~NPC() {};
};
