#pragma once


using Points = double;
//class Weapon;

enum class WeaponType { 
	NoWeapon,
	Blunt,
	Slashing,
	Piercing
};

enum { FISTS_POWER = 20, HOE_POWER = 80, SWORD_POWER = 100, BOW_POWER = 100};



struct Weapon{

public:
	Weapon(const std::string& name): weaponName_(name) {};

	Weapon(const Weapon& /*copied*/) = delete;
	Weapon& operator=(const Weapon& /*copied*/) = delete;

	Weapon(Weapon&& movied);
	Weapon& operator=(Weapon&& movied);
	

	//void changePower(const Points& weaponWear) {};//износ [0,1]
	Points getPower() const;

	const std::string getName();

	virtual WeaponType getType() const
	{
		return WeaponType::NoWeapon;
	}
	virtual ~Weapon() = default;
protected:
	Points weaponPower_;
	std::string weaponName_;
};


struct Fists: public Weapon
{
	Fists(const std::string& name);
	WeaponType getType() const override;
};
struct Hoe: public Weapon
{
	Hoe(const std::string& name);
	WeaponType getType() const override;
};

struct Sword: public Weapon
{
	Sword(const std::string& name);
	WeaponType getType() const override;
};
struct Bow: public Weapon
{
	Bow(const std::string& name);
	WeaponType getType() const override;
};
