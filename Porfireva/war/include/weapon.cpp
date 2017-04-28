#include "weapon.h"
#include "armor.h"

Weapon::~Weapon()
{
}

WeaponType Weapon::getWeaponType() const 
{
    return Type;
}

kg Weapon::getWeaponWeigth() const
{
    return WeaponWeigth;
}

Points Fists::getArmorMaxDamage(ArmorType t) const
{
    switch (t)
    {
        case ArmorType::Lats: return 3;
        case ArmorType::Corslet:return 1;
        case ArmorType::WithoutArmor:return 5;
    }
    assert(!"invalid armor type");
    return 0;
}

Points Bow::getArmorMaxDamage(ArmorType t) const
{
    switch (t)
    {
        case ArmorType::Lats: return 15;
        case ArmorType::Corslet:return 10;
            case ArmorType::WithoutArmor:return 35;
    }
    assert(!"invalid armor type");
    return 0;
}

Points Sword::getArmorMaxDamage(ArmorType t) const
{
    switch (t)
    {
        case ArmorType::Lats: return 10;
        case ArmorType::Corslet:return 10;
            case ArmorType::WithoutArmor:return 20;
    }
    assert(!"invalid armor type");
    return 0;
}

Points Shovel::getArmorMaxDamage(ArmorType t) const
{
    switch (t)
    {
        case ArmorType::Lats: return 5;
        case ArmorType::Corslet:return 3;
        case ArmorType::WithoutArmor:return 10;

    }
    assert(!"invalid armor type");
    return 0;
}

Fists::Fists()
{
    WeaponWeigth = 0;
    Type = WeaponType::Fists;

}

Sword::Sword()
{
    
    WeaponWeigth = 3; 
    Type = WeaponType::Sword;
}

Bow::Bow()
{
    WeaponWeigth = 4; 
    Type=WeaponType::Bow;
}

Shovel::Shovel()
{
    WeaponWeigth = 2;
    Type = WeaponType::Sword;

}
