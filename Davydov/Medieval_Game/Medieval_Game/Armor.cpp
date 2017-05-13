#include "stdafx.h"

#include "..//Medieval_Game/Headers/Armor.h"

/*
struct ChainArmorTraits {
	
	static constexpr Point getProtection(BluntDamage&) { return 10; };
	static constexpr Point getProtection(SlashingDamage&) { return 30; };
	static constexpr Point getProtection(PiercingDamage&) { return 20; };

};
*/
//enum Armors

struct ChainArmor
	: public Armor
{
	ChainArmor()//const std::string&& wName)
	{
	//	ArmorName = wName;
	};
	~ChainArmor() {};

	Point getProtection(DamageType damage) const override
	//Point getProtection(DamageType damage) const override
	{
		switch (damage)
		{
	//	default: break;
		case DamageType::Blunt: return 10;
		case DamageType::Slashing: return 30;
		case DamageType::Piercing: return 20;
		}
	}

	ArmorType getType() const override
	{
		return ArmorType::Chain;
	}

};

struct PlateArmor
	: public Armor
{
	PlateArmor()//const std::string&& wName)
	{
//		ArmorName = wName;
	};

	Point getProtection(DamageType damage) const override
	{
		switch (damage)
		{
		case DamageType::Blunt: return 40;
		case DamageType::Slashing: return 60;
		case DamageType::Piercing: return 40;
		}
	}

	ArmorType getType() const override
	{
		return ArmorType::Plate;
	}

};


struct WithoutArmor
	: public Armor
{
	~WithoutArmor() {
//		this->Armor.delete;
	};
public:
	Point getProtection(DamageType damage) const override
	{
		switch (damage)
		{
		case DamageType::Blunt: return 0;
		case DamageType::Slashing: return 0;
		case DamageType::Piercing: return 0;
		}
	//	assert(!"Invalid damage type");
		return 0;
	}

	ArmorType getType() const override
	{
		return ArmorType::Unarmored;
	}
};


/*
//enum traits 
template<class ArmorTraits>
struct ArmorImpl : public Armor
{};
struct LeatherTraits {

	static constexpr Point getProtection(BluntDamage&) { return 10; };
	static constexpr Point getProtection(SlashingDamage&) { return 20; };
	static constexpr Point getProtection(PiercingDamage&) { return 10; };

};

struct ChainArmorTraits {

	//	template<class DamageType>;
	//	static constexpr Point protection();

	static constexpr Point getProtection(BluntDamage&) { return 10; };
	static constexpr Point getProtection(SlashingDamage&) { return 30; };
	static constexpr Point getProtection(PiercingDamage&) { return 20; };

};


struct LeatherArmor
	: public ArmorImpl<LeatherTraits> {};


struct ChainArmor
	: public ArmorImpl<ChainArmorTraits> {};
*/
/*
	//	enum armor_type { light, heavy };
	//	int defence_against[2][4];

};

struct ChainArmorTraits {
	template<class DamageType>;

	static constexpr Point protection();

	static constexpr Point protection(BluntDamage&)() { return 10; };
	static constexpr Point protection(SlashingDamage&)() { return 30; };
	static constexpr Point protection(PiercingDamage&)() { return 20; };

};
struct PlateArmorTraits {
	template<class DamageType>;

	static constexpr Point protection();

	static constexpr Point protection(BluntDamage&)() { return 20; };
	static constexpr Point protection(SlashingDamage&)() { return 60; };
	static constexpr Point protection(PiercingDamage&)() { return 40; };

};

template<class ArmorTraits>

struct ArmorImpl
	:public Armor {};

struct ChainArmor
	: public ArmorImpl<ChainArmorTraits> {};

struct PlateArmor
	: public ArmorImpl<PlateArmorTraits> {};


*/

/*
enum class ArmorType
{
	Unarmored,
	Chains,
	Plates
};

struct Armor
{
	virtual ~Armor() = 0;

	virtual Point getProtection(DamageType damage) const = 0;
	virtual ArmorType getType() const = 0;
};

Armor::~Armor()
{
}

struct ChainArmor
	: public Armor
{
public:
	Point getProtection(DamageType damage) const override
	{
		switch (damage)
		{
		case DamageType::Blunt: return 10;
		case DamageType::Slashing: return 30;
		case DamageType::Piercing: return 20;
		}
//		assert(!"Invalid damage type");
		return 0;
	}

	ArmorType getType() const override
	{
		return ArmorType::Chains;
	}
};

struct WithoutArmor
	: public Armor
{
public:
	Point getProtection(DamageType damage) const override
	{
		switch (damage)
		{
		case DamageType::Blunt: return 0;
		case DamageType::Slashing: return 0;
		case DamageType::Piercing: return 0;
		}
//		assert(!"Invalid damage type");
		return 0;
	}

	ArmorType getType() const override
	{
		return ArmorType::Unarmored;
	}
};

*/