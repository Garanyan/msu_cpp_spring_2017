#pragma once
//#include "..//MCS_MGame2//Armor.cpp"
#include "..//Medieval_Game/Headers/Units.h"




struct NPC
{
private:
	NPC(const NPC& copied) = delete;
	NPC& operator=(const NPC& copied) = delete;

public:
	int SEV[3]; // basic param
	int skill[5]; // how good with weapons; shovel, sword, bow, hammer
	Point health;
	std::string NPC_name;
	const std::string& getName() const
	{
		return NPC_name;
	}

//	virtual bool eq_armor() const = 0;
//	virtual bool eq_weapon() const = 0;
	
	std::unique_ptr<Weapon> weapon = std::unique_ptr<Fists>(new Fists());
	std::unique_ptr<Armor> armor = std::unique_ptr<WithoutArmor>(new WithoutArmor());

	const /*std::string&*/ void eq_weapon(std::unique_ptr<Weapon> && weapon) {

		weapon = std::move(weapon);
	//	std::cout << this->getName() << " has equipped " << weapon->getName() << std::endl;
	//	return weapon->getName();
	}

	const void /*std::string&*/ eq_armor(std::unique_ptr<Armor> && armor) {
//		armor delete;
		armor.reset(armor.release());
		armor = std::move(armor);
	//	std::cout << this->getName() << " has equipped " << armor->getName() << std::endl;
	//	return armor->getName();
	}

	Point getHealth() {
		return health;
	}
			
	void attack(NPC& attacked) {
	
		const auto protection = attacked.armor->getProtection(weapon->getDamageType());
		const auto damage = weapon->getDamage();

		const auto points = protection - damage;
		if (!points) 
			attacked.health += points;
		

	}



	//	Armor armor;
	//	Weapon weapon;
	//	std::string name;


	NPC() {
//		auto weapon ;
	};
	virtual ~NPC() {};
};

// "enum" traits

template<class NPC_Traits>
struct NPC_Impl : public NPC
{};

// correct
struct PeasantTraits {
/*	static constexpr int  NPC::SEV[0] = { 3 }; // strength
	static constexpr int  NPC::SEV[1] = { 3 }; // endurance
	static constexpr int  NPC::SEV[2] = { 3 }; // velocity

	static constexpr int  NPC::skill[0] = { 20 }; // fists
	static constexpr int  NPC::skill[1] = { 50 }; // shovel
	static constexpr int  NPC::skill[2] = { 10 }; // sword
	static constexpr int  NPC::skill[3] = { 10 }; // bow
	static constexpr int  NPC::skill[4] = { 10 }; // hammer
	*/
};
struct KnightTraits {
	/*static constexpr int  NPC::SEV[0] = { 5 }; // strength
	static constexpr int  NPC::SEV[1] = { 7 }; // endurance
	static constexpr int  NPC::SEV[2] = { 5 }; // velocity

	static constexpr int  NPC::skill[0] = { 20 }; // fists
	static constexpr int  NPC::skill[1] = { 10 }; // shovel
	static constexpr int  NPC::skill[2] = { 50 }; // sword
	static constexpr int  NPC::skill[3] = { 10 }; // bow
	static constexpr int  NPC::skill[4] = { 50 }; // hammer
	*/
};
struct MonkTraits {
	/*static constexpr int  NPC::SEV[0] = { 3 }; // strength
	static constexpr int  NPC::SEV[1] = { 9 }; // endurance
	static constexpr int  NPC::SEV[2] = { 3 }; // velocity

	static constexpr int  NPC::skill[0] = { 60 }; // fists
	static constexpr int  NPC::skill[1] = { 50 }; // shovel
	static constexpr int  NPC::skill[2] = { 10 }; // sword
	static constexpr int  NPC::skill[3] = { 10 }; // bow
	static constexpr int  NPC::skill[4] = { 10 }; // hammer
	*/
};


// "enum" types
struct Peasant : public NPC
{
public:
	Peasant(const std::string&& name)
	{
		NPC_name = name;
		health = 50;
	}
	~Peasant() {};

};

struct Knight : public NPC
{
public:
	Knight(const std::string&& name)
	{
		NPC_name = "Sir " + name;
		health = 60;
	}
	~Knight() {};

};
struct Monk : public NPC
{
public:
	Monk(const std::string&& name)
	{
		NPC_name = "Brother " + name;
		health = 55;
	}
	~Monk() {};

};


/*
class Archer : public NPC
{
public:
	Archer()
	{
		SEV[0] = 3;
		SEV[1] = 5;
		SEV[2] = 5;

		skill[0] = 20;
		skill[1] = 30;
		skill[2] = 80;
		skill[3] = 10;

		weapon_is_eq = false;
		armor_is_eq = false;
	}
	// release eq_...
	~Archer() {};

};
*/

