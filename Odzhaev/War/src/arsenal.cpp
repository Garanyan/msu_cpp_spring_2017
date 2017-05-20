#include "stdafx.h"

#include "../include/arsenal.h"


#include <vector>
#include <memory>


void Arsenal::createWeapons()
{
	for(int i=1; i<5;i++)
		weapons.push_back(std::unique_ptr<Weapon>(new Hoe("hoe" + std::to_string(i))));
	for(int i=1; i<5;i++)
		weapons.push_back(std::unique_ptr<Weapon>(new Sword("sword" + std::to_string(i))));
	for(int i=1; i<5;i++)
		weapons.push_back(std::unique_ptr<Weapon>(new Bow("bow" + std::to_string(i))));

}
void Arsenal::createArmors()
{
	for(int i=1; i<5;i++)
		armors.push_back(Shirt("shirt" + std::to_string(i)));
	for(int i=1; i<5;i++)
		armors.push_back(Plate("plate" + std::to_string(i)));
	for(int i=1; i<5;i++)
		armors.push_back(Chain("Chain" + std::to_string(i)));

}

void Arsenal::putWeapon(std::unique_ptr<Weapon> new_weapon)
{
	weapons.push_back(std::move(new_weapon));
}
void Arsenal::putArmor(Armor new_armor)
{
	armors.push_back(std::move(new_armor));
}
std::unique_ptr<Weapon> Arsenal::getWeapon()
{
	std::unique_ptr<Weapon> weapon = std::move(weapons.back());
	weapons.pop_back();
	return std::move(weapon);
}
Armor Arsenal::getArmor()
{
	Armor armor = std::move(armors.back());
	armors.pop_back();
	return std::move(armor);
}

int Arsenal::countWeapon()
{
	return weapons.size();
}
int Arsenal::countArmor()
{
	return armors.size();
}

void Arsenal::equip(std::unique_ptr<Human>& human) 
{
	if(countArmor()>0) {
		try{
			human->wearArmor(getArmor());
		} catch (std::logic_error) {
		}
	}
		if(countWeapon()>0) {
		try{
			human->takeWeapon(getWeapon());
		} catch (std::logic_error) {
		}
	}
}

void Arsenal::state() 
{
	if(weapons.empty() && armors.empty()) {
		std::cout<<"Arsenal is empty\n";
		return;
		}
	std::cout<<"Number of weapons: "<<weapons.size()<<"\n";
	for(auto it = weapons.begin(); it != weapons.end(); it++) {
		switch((*it)->getType()) {
			case WeaponType::NoWeapon:
				std::cout<<"NoWeapon ";
				break;
			case WeaponType::Blunt:
				std::cout<<"Blunt ";
				break;
			case WeaponType::Slashing:
				std::cout<<"Slashing ";
				break;
			case WeaponType::Piercing:
				std::cout<<"Piercing ";
				break;
			default:
				std::cout<<"o ";

		}
		std::cout<<(*it)->getName()<<std::endl;
	}
	std::cout<<"Number of armor: "<<armors.size()<<"\n";
	for(std::vector<Armor>::iterator it = armors.begin(); it != armors.end(); it++) {
		std::cout<<(*it).getName()<<std::endl;
	}
}

