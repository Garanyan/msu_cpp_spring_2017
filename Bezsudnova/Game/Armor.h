#pragma once

class Armor
{
public:
    virtual ArmorType getArmorType() = 0;
	virtual int getDefence(WeaponType weapon_) = 0;
	virtual ~Armor(){}
};

class Chain : public Armor
{
public:
    ArmorType getArmorType(void);
    int getDefence(WeaponType weapon_);
};

class Lats : public Armor
{
public:
    ArmorType getArmorType(void);
    int getDefence(WeaponType weapon_);
};

//chain
ArmorType Chain::getArmorType(void)
	{
	    return ArmorType::Chain;
	}

int Chain::getDefence(WeaponType weapon_)
	{
		switch(weapon_)
		{
		    case WeaponType::Hammer: return 20;
		    case WeaponType::Sword: return 20;
		    case WeaponType::Shovel : return 5;
		    case WeaponType::Bow: return 5;
		}
		return 0;
	}

//lats
ArmorType Lats::getArmorType(void)
	{
	    return ArmorType::Lats;
	}

int Lats::getDefence(WeaponType weapon_)
	{
		switch(weapon_)
		{
		    case WeaponType::Hammer: return 5;
		    case WeaponType::Sword: return 5;
		    case WeaponType::Shovel : return 20;
		    case WeaponType::Bow: return 20;
		}
		return 0;
	}
