
#include "unit.h"
#include "arsenal.h"
#include "armor.h"

Unit::Unit(const std::string& name, Points force):UnitName(name),Force(force)
{
}
Unit::~Unit()
{
}

//Plowman::Plowman(const std::string& name):Unit(name,500);

const std::string Unit::getName()const
{
    return UnitName;
}



void Archer::WearArmor(Arsenal& a)
{
    if (a.anyLats >0)
    {
        UnitArmor.reset(a.useLats.release());
    }
    else if(a.anyCorslet >0)
    {
        UnitArmor.reset(a.useCorslet.release());
    }
    else {
    }
}
/*void Knight::WearArmor(Arsenal& a)
{
    if (a.armory[Lats] >0)
    {
        std::unique_ptr <Armor> lats =  a.useLats;
        armor_.reset(lats.release());
    }
    else if(a.armory[Corslet] >0)
    {
        std::unique_ptr <Armor>corslet = a.useCorslet;
        armor_.reset(corslet.release());
    }
    else {
        ArmorType::Unarmored unarmored;
        armor_.reset(corslet.release());
        
    }
}
void Plowman::WearArmor(Arsenal& a)
{
    if (a.armory[Lats] >0)
    {
        std::unique_ptr <Armor>lats =  a.useLats;
        armor_.reset(lats.release());
    }
    else if(a.armory[Corslet] >0)
    {
        corslet = a.useCorslet;
        armor_.reset(corslet.release());
    }
    else {
        ArmorType::Unarmored unarmored;
        armor_.reset(corslet.release());
        
    }
}*/

