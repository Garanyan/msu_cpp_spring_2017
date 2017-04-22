#include "armor.h"

kg Armor::getArmorWeigth() const{
    return ArmorWeigth;
}

ArmorType Armor::getArmorType()const{
    return Type;
}

Corslet::Corslet()
{
    ArmorWeigth = 4;
    Type = ArmorType::Corslet;
}

Lats::Lats()
{
    ArmorWeigth = 5;
    Type = ArmorType::Lats;
}