#include "arsenal.h"


Arsenal::Arsenal()
{
    armory[ArmorType::Lats] = 1;
    armory[ArmorType::Lats] = 1;
    weaponary[WeaponType::Bow] = 1;
    weaponary[WeaponType::Sword] = 1;
    weaponary[WeaponType::Shovel] = 1;
}

std::unique_ptr <Armor> Arsenal::createLats()
{
    return std::unique_ptr<Armor>(new Lats());
}
std::unique_ptr <Armor> Arsenal::createCorslet()
{
    return std::unique_ptr<Armor>(new Corslet());
}
std::unique_ptr <Armor> Arsenal::createNoArmor()
{
    return std::unique_ptr<Armor>(new WithoutArmor());
}
std::unique_ptr <Weapon> Arsenal::createBow()
{
    return std::unique_ptr<Weapon>(new Bow());
}
std::unique_ptr <Weapon> Arsenal::createSword()
{
    return std::unique_ptr<Weapon>(new Sword());
}
std::unique_ptr <Weapon> Arsenal::createShovel()
{
    return std::unique_ptr<Weapon>(new Shovel());
}
std::unique_ptr <Weapon> Arsenal::createFists()
{
    return std::unique_ptr<Weapon>(new Fists());
}

bool Arsenal::anyLats() const 
{
    return armory.find(ArmorType::Lats)->second > 0;
}
bool Arsenal::anyCorslet() const
{
    return armory.find(ArmorType::Corslet)->second > 0;
}
bool Arsenal::anyBow() const
{
    return weaponary.find(WeaponType::Bow)->second > 0;
}
bool Arsenal::anySword() const
{
    return weaponary.find(WeaponType::Sword)->second > 0;
}
bool Arsenal::anyShovel() const
{
    return weaponary.find(WeaponType::Shovel)->second > 0;
}

std::unique_ptr <Armor> Arsenal::useLats()
{
    armory[ArmorType::Lats] -= 1;
    return createLats();
}
std::unique_ptr <Armor> Arsenal::useCorslet()
{
    armory[ArmorType::Corslet] -= 1;
    return createCorslet();
}
std::unique_ptr <Armor> Arsenal::unArmored()
{
    return createNoArmor();
}
std::unique_ptr <Weapon> Arsenal::useBow()
{
    weaponary[WeaponType::Bow] -= 1;
    return createBow(); 
}
std::unique_ptr <Weapon> Arsenal::useSword()
{
    weaponary[WeaponType::Sword] -= 1;
    return createSword(); 
} 
std::unique_ptr <Weapon> Arsenal::useShovel()
{
    weaponary[WeaponType::Shovel] -= 1;
    return createShovel(); 
} 
std::unique_ptr <Weapon> Arsenal::useFists()
{
    return createFists(); 
} 

