#include "Weapon.h"

// Weapon
Weapon::Weapon(Points durability, Points damage, Points breakingSpeed):
        durability_(durability),
        damage_(damage),
        breakingSpeed_(breakingSpeed)
{
}
void Weapon::printStats() const
{
    std::cout << getName() << " dur=" << durability_;
}
Points Weapon::takeAndReturnDamage(Points armorResistance)
{
    auto damage = damage_ * durability_;
    if(durability_ > 0)
        durability_ -=  breakingSpeed_ * (1 + armorResistance);
    return damage_;
}
Points Weapon::getDurability() const
{
    return durability_;
}
Weapon::~Weapon()
{
}

// Fists
Fists::Fists(Points durability, Points damage, Points breakingSpeed):
        Weapon(durability, damage, breakingSpeed)
{
}
DamageType Fists::damageType() const
{
    return DamageType::Blunt;
}
std::string Fists::getName() const
{
    return "Fists";
}

// Sword
Sword::Sword(Points durability, Points damage, Points breakingSpeed):
    Weapon(durability, damage, breakingSpeed)
{
}
DamageType Sword::damageType() const
{
    return DamageType::Slashing;
}
std::string Sword::getName() const
{
    return "Sword";
}

// Bow
Bow::Bow(Points durability, Points damage, Points breakingSpeed):
    Weapon(durability, damage, breakingSpeed)
{
}
DamageType Bow::damageType() const
{
    return DamageType::Piercing;
}
std::string Bow::getName() const
{
    return "Bow";
}

