#pragma once

#include "../include/weapon.h"
#include "../include/armor.h"
#include "../include/human.h"
class Arsenal
{
private:
	std::vector<std::unique_ptr<Weapon>> weapons;
	std::vector<Armor> armors;

public:
	void createWeapons();
	void createArmors();
	
	void putWeapon(std::unique_ptr<Weapon>);
	void putArmor(Armor);		
	
	std::unique_ptr<Weapon> getWeapon();
	Armor getArmor();

	int countWeapon();
	int countArmor();		
	
	void equip(std::unique_ptr<Human>& human);
	void state();
};
