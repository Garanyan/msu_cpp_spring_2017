#pragma once

class Weapon
{
public:
	virtual WeaponType getWeaponType() = 0;
	virtual int getPower(ArmorType armor_) = 0;
	virtual ~Weapon(){}
};

class Sword : public Weapon
{
public:
    WeaponType getWeaponType(void);
	int getPower(ArmorType armor_);
};

class Hammer: public Weapon
{
public:
	WeaponType getWeaponType(void);
	int getPower(ArmorType armor_);
};

class Shovel: public Weapon
{
public:
    WeaponType getWeaponType(void);
    int getPower(ArmorType armor_);
};

class Bow: public Weapon
{
public:
	WeaponType getWeaponType(void);
	int getPower(ArmorType armor_);
};


//sword
WeaponType Sword::getWeaponType(void)
	{
	    return WeaponType::Sword;
	};

int Sword::getPower(ArmorType armor_)
	{
		switch(armor_)
		{
		    case ArmorType::Chain: return 15;
		    case ArmorType::Lats : return 10;
		}
		return 0;
	};

//hammer
WeaponType Hammer::getWeaponType(void)
	{
		return WeaponType::Hammer;
	};

int Hammer::getPower(ArmorType armor_)
	{
		switch(armor_)
		{
		    case ArmorType::Chain: return 15;
		    case ArmorType::Lats : return 10;
		}
		return 0;
	};

//shovel
WeaponType Shovel::getWeaponType(void)
	{
		return WeaponType::Shovel;
	};

int Shovel::getPower(ArmorType armor_)
	{
		switch(armor_)
		{
		    case ArmorType::Chain: return 10;
		    case ArmorType::Lats : return 15;
		}
		return 0;
	};

//bow
WeaponType Bow::getWeaponType(void)
	{
		return WeaponType::Bow;
	}

int Bow::getPower(ArmorType armor_)
	{
		switch(armor_)
		{
		    case ArmorType::Chain: return 10;
		    case ArmorType::Lats : return 15;
		}
		return 0;
	}
