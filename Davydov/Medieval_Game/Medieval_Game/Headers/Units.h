#pragma once

struct NPC
{
public:
	std::string NPC_name;
	const std::string& getName();
	//std::unique_ptr<Weapon> weapon = std::unique_ptr<Fists>(new Fists());
	//std::unique_ptr<Armor> armor = std::unique_ptr<WithoutArmor>(new WithoutArmor());

	const /*std::string&*/ void eq_weapon(std::unique_ptr<Weapon> && weapon);
	const void /*std::string&*/ eq_armor(std::unique_ptr<Armor> && armor);
	Point getHealth();

	void attack(NPC& attacked);
};
