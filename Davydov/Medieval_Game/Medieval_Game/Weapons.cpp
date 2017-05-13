#include "stdafx.h"

#include "..//Medieval_Game/Headers/Weapons.h"



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
