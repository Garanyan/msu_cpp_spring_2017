#pragma once
#include<cassert>
#include"armor.h"
using Points = double;
using kg = double;



enum class WeaponType
{
    Fists,
    Bow,
    Sword,
    Shovel,
};

class Weapon
{
protected:
    kg WeaponWeigth;
    WeaponType Type;
        
public:
    Weapon ()= default;
    virtual ~Weapon() = 0;
    virtual Points getArmorMaxDamage(ArmorType) const = 0;
    kg getWeaponWeigth() const;
    WeaponType getWeaponType() const;
    Weapon(Weapon const&) = delete;
    Weapon& operator= (Weapon const&) = delete;
    
};

class Fists
:public Weapon
{
public:
    Fists();
    Points getArmorMaxDamage(ArmorType) const override;
 //   kg getWeaponWeigth() const override;
//    WeaponType getWeaponType() const override;
};

class Bow
: public Weapon
{
public:
    Bow();
    Points getArmorMaxDamage(ArmorType) const override;
 //   kg getWeaponWeigth() const override;
 //   WeaponType getWeaponType() const override;
};

class Sword
: public Weapon
{
public:Sword();
    Points getArmorMaxDamage(ArmorType) const override;
 //   kg getWeaponWeigth() const override;
 //   WeaponType getWeaponType() const override;
};

class Shovel
: public Weapon
{
public:
    Shovel();
    Points getArmorMaxDamage(ArmorType) const override;
 //   kg getWeaponWeigth() const override;
 //   WeaponType getWeaponType() const override;
};

