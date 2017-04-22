#pragma once
#include<string>
using Points = int;
class Arsenal;
class Armor;
class Weapon;

class Unit{
protected:
    const std::string UnitName;
    Points Force;
    std::unique_ptr <Armor> UnitArmor;
  public:
    Unit(const std::string&, Points);
    virtual ~Unit();
    const std::string getName() const;
    virtual void WearArmor(Arsenal&) = 0;
    //virtual void TakeWeapon(Arsenal&);
    void Attack(Unit& other);
    virtual ArmorType favoriteArmor();

};

/*class Plowman final
:public Unit{
public:
    explicit Plowman(std::string&);
    void WearArmor(Arsenal&) override;
    void TakeWeapon(Arsenal&) override;
};*/

class Archer
:public Unit{
public:
    explicit Archer(std::string&) : Unit("", 0) {}
    void WearArmor(Arsenal&) override;
    //void TakeWeapon(Arsenal&) override;
};

/*class Knight final
:public Unit{
public:
    explicit Knight(std::string&);
    void WearArmor(Arsenal&) override;
    void TakeWeapon(Arsenal&) override;
};*/
