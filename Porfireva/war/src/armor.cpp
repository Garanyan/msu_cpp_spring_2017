#include "../include/armor.h"

Armor::~Armor()
{
    
}

kg Armor::getArmorWeigth() const{
    return ArmorWeigth;
}

ArmorType Armor::getArmorType()const{
    return Type;
}

Corslet::Corslet()
{
    ArmorWeigth = 5;
    Type = ArmorType::Corslet;
}

Lats::Lats()
{
    ArmorWeigth = 5;
    Type = ArmorType::Lats;
}
WithoutArmor::WithoutArmor()
{
    ArmorWeigth = 0;
    Type = ArmorType::WithoutArmor;
}
