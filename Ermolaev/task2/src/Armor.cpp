#include "Armor.h"

// Armor
Armor::Armor(Points durability, Points breakingSpeed, Points damageToWeapon):
            durability_(durability),
            breakingSpeed_(breakingSpeed),
            damageToWeapon_(damageToWeapon)
{
}
void Armor::printStats() const
{
    std::cout << getName() << " dur=" << durability_;
}
Points Armor::takeAndTransferDamage(Points damage, DamageType type)
{
    if(durability_ > 0)
    {
        durability_ -= damage * breakingSpeed_;
        return damage * transferDamage(type);
    }
    else
    {
        return damage;
    }
}
Points Armor::getDurability() const
{
    return durability_;
}
Points Armor::getDamageToWeapon() const
{
    return damageToWeapon_;
}
Armor::~Armor()
{
}

// WithoutArmor
WithoutArmor::WithoutArmor(Points durability, Points breakingSpeed, Points damageToWeapon):
        Armor(durability, breakingSpeed, damageToWeapon)
{
}
Points WithoutArmor::transferDamage(DamageType damage) const
{
    switch(damage)
    {
        case DamageType::Blunt :
            return 1;
        case DamageType::Piercing :
            return 1;
        case DamageType::Slashing :
            return 1;
        default:
            assert(!"Invalid damage value");
            return 0;
    }
}
std::string WithoutArmor::getName() const
{
    return "WithoutArmor";
}

// Chains
Chains::Chains(Points durability, Points breakingSpeed, Points damageToWeapon):
     Armor(durability, breakingSpeed, damageToWeapon)
{
}
Points Chains::transferDamage(DamageType damage) const
{
    switch(damage)
    {
        case DamageType::Blunt :
            return 0.5;
        case DamageType::Piercing :
            return 0.7;
        case DamageType::Slashing :
            return 0.9;
        default:
            assert(!"Invalid damage value");
            return 0;
    }
}
std::string Chains::getName() const
{
    return "Chains";
}


// Plates
Plates::Plates(Points durability, Points breakingSpeed, Points damageToWeapon):
     Armor(durability, breakingSpeed, damageToWeapon)
{
}
Points Plates::transferDamage(DamageType damage) const
{
    switch(damage)
    {
        case DamageType::Blunt :
            return 0.4;
        case DamageType::Piercing :
            return 0.7;
        case DamageType::Slashing :
            return 0.9;
        default:
            assert(!"Invalid damage value");
            return 0;
    }
}
std::string Plates::getName() const
{
    return "Plates";
}