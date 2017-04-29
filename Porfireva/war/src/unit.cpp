#include <iostream>
#include "../include/unit.h"
#include "../include/arsenal.h"
#include "../include/armor.h"

Unit::Unit(const std::string& name, Points force):UnitName(name),Force(force)
{

    std::cout << UnitName <<" has appeared" << std::endl; 
}
Unit::~Unit()
{
}
const kg Unit::getEquipmentWeigth() const
{
    return UnitArmor->getArmorWeigth()+UnitWeapon->getWeaponWeigth();
}


const std::string Unit::getName()const
{
    return UnitName;
}
Archer::Archer(const std::string& S, Arsenal& A):Unit(S,45)
{
    WearArmor(A);
    TakeWeapon(A);
}

void Archer::WearArmor(Arsenal& a)
{
    if (a.anyLats())
    {
        UnitArmor.reset(a.useLats().release());
        std::cout << UnitName << " wears lats"<<std::endl;
    }
    else if(a.anyCorslet())
    {
        UnitArmor.reset(a.useCorslet().release());
        std::cout << UnitName << " wears corslet"<<std::endl;
    }
    else {
        UnitArmor.reset(a.unArmored().release());
        std::cout << UnitName << " is unarmored"<<std::endl;
    }
}

Plowman::Plowman(const std::string& S, Arsenal& A):Unit(S,45)
{
    WearArmor(A);
    TakeWeapon(A);
}

void Plowman::WearArmor(Arsenal& a)
{
    if (a.anyLats())
    {
        UnitArmor.reset(a.useLats().release());
        std::cout << UnitName << " wears lats"<<std::endl;

    }
    else if(a.anyCorslet())
    {
        UnitArmor.reset(a.useCorslet().release());
        std::cout << UnitName << " wears corslet"<<std::endl;

    }
    else {
        UnitArmor.reset(a.unArmored().release());
        std::cout << UnitName << " is unarmored"<<std::endl;
    }
}
Knight::Knight(const std::string& S, Arsenal& A):Unit(S,45)
{
    WearArmor(A);
    TakeWeapon(A);
}

void Knight::WearArmor(Arsenal& a)
{
    if(a.anyCorslet())
    {
        UnitArmor.reset(a.useCorslet().release());
        std::cout << UnitName << " wears corslet"<<std::endl;
    }
    else if (a.anyLats())
    {
        UnitArmor.reset(a.useLats().release());
        std::cout << UnitName << " wears lats"<<std::endl;

    }
    else {
        UnitArmor.reset(a.unArmored().release());
         std::cout << UnitName << " is unarmored"<<std::endl;
    }
}

void Archer::TakeWeapon(Arsenal& a)
{
    if (a.anyBow())
    {
        UnitWeapon.reset(a.useBow().release());
        std::cout << UnitName << " uses bow"<<std::endl;
        CurrentWeaponSkill = 1;
    }
    else if(a.anyShovel())
    {
        UnitWeapon.reset(a.useShovel().release());
        std::cout << UnitName << " uses shovel"<<std::endl;
        CurrentWeaponSkill = 0.8;
    }
    else if(a.anySword()) {
        UnitWeapon.reset(a.useSword().release());
        std::cout << UnitName << " uses sword"<<std::endl;
        CurrentWeaponSkill = 0.6;
    }
    else {
        UnitWeapon.reset(a.useFists().release());
        std::cout << UnitName << " uses fists"<<std::endl;
        CurrentWeaponSkill = 1;
    }
}
void Plowman::TakeWeapon(Arsenal& a)
{
    if(a.anyShovel())
    {
        UnitWeapon.reset(a.useShovel().release());
        std::cout << UnitName << " uses shovel"<<std::endl;
        CurrentWeaponSkill = 1;
    }
    else if (a.anyBow())
    {
        UnitWeapon.reset(a.useBow().release());
        std::cout << UnitName << " uses bow"<<std::endl;
        CurrentWeaponSkill = 0.8;
    }
    else if(a.anySword()) {
        UnitWeapon.reset(a.useSword().release());
        std::cout << UnitName << " uses sword"<<std::endl;
        CurrentWeaponSkill = 0.6;
    }
    else {
        UnitWeapon.reset(a.useFists().release());
        std::cout << UnitName << " uses fists"<<std::endl;
        CurrentWeaponSkill = 1;
    }
}
void Knight::TakeWeapon(Arsenal& a)
{
    if(a.anySword()) {
        UnitWeapon.reset(a.useSword().release());
        std::cout << UnitName << " uses sword"<<std::endl;
        CurrentWeaponSkill = 1;
    }
    
    else if(a.anyShovel())
    {
        UnitWeapon.reset(a.useShovel().release());
        std::cout << UnitName << " uses shovel"<<std::endl;
        CurrentWeaponSkill = 0.8;
    }
    else if (a.anyBow())
    {
        UnitWeapon.reset(a.useBow().release());
        std::cout << UnitName << " uses bow"<<std::endl;
        CurrentWeaponSkill = 0.6;
    }
   
    else {
        UnitWeapon.reset(a.useFists().release());
        std::cout << UnitName << " uses fists"<<std::endl;
        CurrentWeaponSkill = 1;
    }
}
void Unit::LowForce(Points p)
{
    Force-=p;
}
const Points Unit::getForce() const
{
    return Force;
}
int Unit::Attack(Unit& other)
{
    std::cout << UnitName<<" attaks " << other.getName() << std::endl;
    Force -= getEquipmentWeigth()/10;
    other.LowForce(CurrentWeaponSkill*UnitWeapon->getArmorMaxDamage(other.UnitArmor->getArmorType()));
    std::cout << UnitName<<"`s force is "<<Force<<", " << other.getName()<<"`s force is "<<other.getForce()<< std::endl;
    if (other.getForce()<0) return -2;
    if(Force < 0) return -1;
    return 0;
}



