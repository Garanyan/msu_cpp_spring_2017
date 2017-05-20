#pragma once

#include <string>
using Points = double;
struct Weapon;

enum { WITHOUTARMOR_STAMINA = 5, SHIRT_STAMINA = 10, CHAIN_STAMINA = 100, PLATE_STAMINA = 200};

enum class ArmorType {
    Unarmored,
    Chains,
    Plates
};


struct Armor{

public:
	Armor(const std::string& name): armorName_(name){};

	Armor(const Armor& /*copied*/) = delete;
	Armor& operator=(const Armor& /*copied*/) = delete;


	Armor(Armor&& movied);
	Armor& operator=(Armor&& movied);
	
	
	void changeStamina(const Points& armorWear);//износ брони [0,1]
	Points getProtection() const;
	std::string getName() const;
	//virtual ArmorType getType() const = 0;
	virtual ~Armor() = default;
protected:
	Points armorStamina_;
	std::string armorName_;
};


struct WithoutArmor: public Armor
{
	WithoutArmor(const std::string& name): Armor(name)
	{
		armorStamina_ = WITHOUTARMOR_STAMINA; 
	}
};
struct Shirt: public Armor
{
	Shirt(const std::string& name): Armor(name)
	{
		armorStamina_ = SHIRT_STAMINA;	
	}
};

struct Plate: public Armor
{
	Plate(const std::string& name): Armor(name)
	{
		armorStamina_ = PLATE_STAMINA;
	}
};
struct Chain: public Armor
{
	Chain(const std::string& name): Armor(name)
	{
		armorStamina_ = CHAIN_STAMINA;
	}
};
