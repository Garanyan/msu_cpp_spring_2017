#pragma once
#include<cassert>
using Points = int;
using kg = double;

class Armor;

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
    virtual Points getArmorMaxDamage(const Armor&) const = 0;
    virtual kg getWeaponWeigth() const = 0;
    virtual WeaponType getWeaponType() const = 0;
    Weapon(Weapon const&) = delete;
    Weapon& operator= (Weapon const&) = delete;
    
};

class Fists
:public Weapon
{
public:
    Fists();
    Points getArmorMaxDamage(const Armor&) const override;
    kg getWeaponWeigth() const override;
    WeaponType getWeaponType() const override;
};

class Bow
: public Weapon
{
public:
    Bow();
    Points getArmorMaxDamage(const Armor&) const override;
    kg getWeaponWeigth() const override;
    WeaponType getWeaponType() const override;
};

class Sword
: public Weapon
{
public:Sword();
    Points getArmorMaxDamage(const Armor&) const override;
    kg getWeaponWeigth() const override;
    WeaponType getWeaponType() const override;
};

class Shovel
: public Weapon
{
public:
    Shovel();
    Points getArmorMaxDamage(const Armor&) const override;
    kg getWeaponWeigth() const override;
    WeaponType getWeaponType() const override;
};

