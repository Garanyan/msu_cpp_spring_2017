#pragma once

class Units
{
public:
	std::string name_;
	unique_ptr<Armor> armor_;
	unique_ptr<Weapon> weapon_;
	int lifes;
    UnitType type_;

    Units();


	virtual double getSkillArmor() = 0;
    virtual double getSkillWeapon() = 0;
	WeaponType getWeapon ();
	ArmorType getArmor();
};

class Peasant:public Units
{
public:
    Peasant(string name, UnitType unit_);

    double getSkillArmor();
    double getSkillWeapon();
};

class Knight:public Units
{
public:
    Knight(string name, UnitType unit_);

    double getSkillArmor();
    double getSkillWeapon();
};

class Archer:public Units
{
public:
    Archer(string name, UnitType unit_);

    double getSkillArmor();
    double getSkillWeapon();
};


Units::Units()
    {
    };

WeaponType Units::getWeapon ()
	{
		return weapon_->getWeaponType();
	}

ArmorType Units::getArmor()
	{
		return armor_->getArmorType();
	}




Peasant::Peasant(string name, UnitType unit_)
	{
		name_ = name;
		lifes = 100;
		type_ = unit_;
	};

double Peasant::getSkillArmor()
    {
        ArmorType typeArmor_ = armor_->getArmorType();
        switch(typeArmor_)
        {
            case ArmorType::Chain : return 1;
            case ArmorType::Lats : return 3;
        }
        return 0;
    }

double Peasant::getSkillWeapon()
    {
        WeaponType typeWeapon_ = weapon_->getWeaponType();
        switch(typeWeapon_)
        {
            case WeaponType::Hammer : return 1;
            case WeaponType::Sword : return 1;
            case WeaponType::Shovel : return 3;
            case WeaponType::Bow : return 3;
        }
        return 0;
    };


Knight::Knight(string name, UnitType unit_)
	{
		name_ = name;
		lifes = 100;
		type_ = unit_;
	};

double Knight::getSkillArmor()
    {
        ArmorType typeArmor_ = armor_->getArmorType();
        switch(typeArmor_)
        {
            case ArmorType::Chain : return 2;
            case ArmorType::Lats : return 2;
        }
        return 0;
    };

double Knight::getSkillWeapon()
    {
        WeaponType typeWeapon_ = weapon_->getWeaponType();
        switch(typeWeapon_)
        {
            case WeaponType::Hammer : return 2;
            case WeaponType::Sword : return 2;
            case WeaponType::Shovel : return 2;
            case WeaponType::Bow : return 2;
        }
        return 0;
    }



Archer::Archer(string name, UnitType unit_)
	{
		name_ = name;
		lifes = 100;
		type_ = unit_;
	}

double Archer::getSkillArmor()
    {
        ArmorType typeArmor_ = armor_->getArmorType();
        switch(typeArmor_)
        {
            case ArmorType::Chain : return 3;
            case ArmorType::Lats : return 1;
        }
        return 0;
    }

double Archer::getSkillWeapon()
    {
        WeaponType typeWeapon_ = weapon_->getWeaponType();
        switch(typeWeapon_)
        {
            case WeaponType::Hammer : return 3;
            case WeaponType::Sword : return 3;
            case WeaponType::Shovel : return 1;
            case WeaponType::Bow : return 1;
        }
        return 0;
    }
