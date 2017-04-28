#pragma once
#include<string>
#include"armor.h"
using Points = double;
using kg = double;
class Arsenal;
class Armor;
class Weapon;

class Unit{
protected:
    const std::string UnitName;
    Points Force;
    Points CurrentWeaponSkill;
    std::unique_ptr <Armor> UnitArmor;
    std::unique_ptr <Weapon> UnitWeapon;
    virtual void WearArmor(Arsenal&) = 0;
    virtual void TakeWeapon(Arsenal&) = 0;
    const kg getEquipmentWeigth() const;
  public:
    Unit(const std::string&, Points);
    virtual ~Unit();
    const std::string getName() const;
    const Points getForce() const;
    int Attack(Unit&);
    void LowForce(Points);

};

class Plowman final
:public Unit{
protected:
    void WearArmor(Arsenal&) override;
    void TakeWeapon(Arsenal&) override;
public:
    explicit Plowman(const std::string&, Arsenal&);
    };


class Archer final
:public Unit{
protected:
    void WearArmor(Arsenal&) override;
    void TakeWeapon(Arsenal&) override;
public:
    explicit Archer(const std::string&, Arsenal&);
};

class Knight final
:public Unit{
protected:
    void WearArmor(Arsenal&) override;
    void TakeWeapon(Arsenal&) override;
public:
    explicit Knight(const std::string&, Arsenal&);
};

