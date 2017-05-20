#pragma once

//#include <map>
#include "armor.h"
#include "weapon.h"
#include <memory>


enum { PEASANT_POWER = 20, KNIGHT_POWER = 80, ARCHER_POWER = 100,
	PEASANT_HEALTH = 20, KNIGHT_HEALTH = 80, ARCHER_HEALTH = 100,
	PEASANT_SPEED = 20, KNIGHT_SPEED = 80, ARCHER_SPEED = 100};
enum class HumanType
{
	HUMAN,
	PEASANT,
	KNIGHT,
	ARCHER
};
using Points = double;

class Human
{

private:
	std::string name_;
	Points power_;
	Points health_;
	Points speed_;
	std::unique_ptr<Weapon> weapon_;
	Armor armor_;

public:

	Human(const std::string& name, const Points& power,const Points& health,const Points& speed)
		: name_(name)
		, power_(power)
		, health_(health)
		, speed_(speed)
		, armor_(std::move(WithoutArmor("Body")))
		, weapon_(new Fists("MyFists"))
	{};

	Human(const Human& copied) = delete;
	Human& operator=(const Human& copied) = delete;

	Human(Human&& movied)
		: name_(movied.name_)
		, power_(movied.power_)
		, health_(movied.health_)
		, speed_(movied.speed_)
		, armor_(std::move(movied.armor_))
		, weapon_(std::move(movied.weapon_))
	{
		movied.setSkills(0,0,0);
		movied.name_="by";
	}
	void wearArmor(Armor&& new_armor);
	void takeWeapon(std::unique_ptr<Weapon> new_weapon);

	void attack(Human& enemy);

	void attack(std::unique_ptr<Human>& enemy);


	const std::string getName();
	int getTotalPower();
	int getHealth();
	bool changeHealth(const int& flag, const Points& change);
	void setSkills(const Points& power,const Points& health,const Points& speed);
	virtual HumanType getType() const = 0;
	virtual ~Human() = default;
};

class Peasant: public Human
{
public:
	explicit Peasant(const std::string&name): Human(name,PEASANT_POWER,PEASANT_HEALTH,PEASANT_SPEED) {}
	HumanType getType() const override
	{return HumanType::PEASANT;}
};

class Knight: public Human
{
public:
	explicit Knight(const std::string&name): Human(name, KNIGHT_POWER,KNIGHT_HEALTH,KNIGHT_SPEED) {}
	HumanType getType() const override
	{return HumanType::KNIGHT;}
};

class Archer: public Human
{
public:
	explicit Archer(const std::string&name): Human(name,ARCHER_POWER,ARCHER_HEALTH,ARCHER_SPEED) {}
	HumanType getType() const override
	{return HumanType::ARCHER;}
};
