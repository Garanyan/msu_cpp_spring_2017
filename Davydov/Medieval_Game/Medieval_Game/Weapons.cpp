#pragma once
#include <string>


using Point = double;

enum class DamageType
{
	Blunt,
	Slashing,
	Piercing
};
enum class WeaponType
{
	Martial,
	Swords,
	Hummers,
};

struct BluntDamage {};
struct SlashingDamage {};
struct PiercingDamage {};


class Weapon
{
private:
	Weapon(const Weapon& copied) = delete;
	Weapon& operator=(const Weapon& copied) = delete;

public:
	Weapon() {};
	virtual ~Weapon() {};
	//	enum weapon_type { shovel, sword, bow, hammer };
	//	int penetration[4][2];
	std::string WeaponName;
	virtual DamageType getDamageType() const = 0;
	virtual Point getDamage() const = 0;
	virtual WeaponType getType() const = 0;
	
	const std::string& getName() const
	{
		return WeaponName;
	}

};
//enum traits 
template<class WeaponTraits>
struct WeaponImpl : public Weapon
{};

struct BowTraits {
	using Type = PiercingDamage;
	static constexpr Point damage = 20;
};

struct HummerTraits {
	using Type = BluntDamage;
	static constexpr Point damage = 30;
};

//enum weapons

struct Fist
	: public Weapon
{
	DamageType getDamageType() const override
	{
		return DamageType::Blunt;
	}
	Point getDamage() const override
	{
		return 10;
	}

	WeaponType getType() const override
	{
		return WeaponType::Martial;
	}

};
struct Hummer
	: public Weapon
{
	Hummer()//const std::string&& wName) 
	{
//		WeaponName = wName;
	};

	DamageType getDamageType() const override
	{
		return DamageType::Blunt;
	}
	Point getDamage() const override
	{
		return 50;
	}

	WeaponType getType() const override
	{
		return WeaponType::Hummers;
	}

};
//struct Bow {};

struct Fists
	: public Weapon
{
	DamageType getDamageType() const override
	{
		return DamageType::Blunt;
	}

	Point getDamage() const override // override проверка от выстрела в ногу - если функци€ виртуальна, всЄ работает, если нет - выбросит ошибку компил€ции
	{
		return 5;
	}

	WeaponType getType() const override
	{
		return WeaponType::Martial;
	}
};
