#include "stdafx.h"

#include "../include/weapon.h"
#include "../include/armor.h"
#include "../include/human.h"

#include <memory>




void Human::wearArmor(Armor&& new_armor)
{
	armor_ = std::move(new_armor);
}
void Human::takeWeapon(std::unique_ptr<Weapon> new_weapon)
{
	weapon_ = std::move(new_weapon);
}

void Human::attack(Human& enemy)
{
	Points damage = enemy.armor_.getProtection()-getTotalPower();
	std::cout<<" stam "<<enemy.armor_.getName()<<std::endl;

	std::cout<<enemy.armor_.getProtection()<<" "<<getTotalPower()<<" " <<weapon_->getPower();
	if(damage<0)
	{
		enemy.changeHealth(1, damage);
	}
}

void Human::attack(std::unique_ptr<Human>& enemy)
{
	Points damage = enemy->armor_.getProtection()-getTotalPower();
	std::cout<<"unique stam "<<enemy->armor_.getName()<<std::endl;
	std::cout<<enemy->armor_.getProtection()<<" "<<getTotalPower()<<" " <<weapon_->getPower();
	if(damage<0)
	{
		enemy->changeHealth(1, damage);
	}
}


const std::string Human::getName()
{
	return name_;
}
int Human::getTotalPower()
{
	return power_ + weapon_->getPower();
}
int Human::getHealth()
{
	return health_;
}
bool Human::changeHealth(const int& flag, const Points& change)
{
	switch(flag)
	{
		case 0:
		{
			health_= 100;//???
			return true;
		}
		case 1:
		{	
			health_+=change;
		}
	}
	if(health_<=0)
	{
		return false;
	}
	return true;
}
void Human::setSkills(const Points& power,const Points& health,const Points& speed)
{
	power_=power;
	health_=health;
	speed_=speed;		
}
