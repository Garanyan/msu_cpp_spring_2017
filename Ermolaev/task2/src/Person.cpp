#include "Person.h"

// Person
Person::Person(std::string name, Points health):
    name_(name),
    health_(health),
    armor_(new WithoutArmor()),
    weapon_(new Fists())
{
}
void Person::printStats()
{
    std::cout << getJob() << " "<< name_ << " health=" << health_ << " ";
    weapon_->printStats(); std:: cout << " ";
    armor_->printStats(); std::cout << std::endl;
}
void Person::attack(Person &enemy)
{
    if((weapon_->getDurability() < 0) && (weapon_->getName() != "Fists"))
        weapon_.reset(new Fists());
    if((armor_->getDurability() < 0) && (armor_->getName() != "WithoutArmor"))
        armor_.reset(new WithoutArmor());

    const auto enemyArmorResistance = enemy.armor_->transferDamage(weapon_->damageType());
    const auto damageFromWeapon = weapon_->takeAndReturnDamage(enemyArmorResistance);
    const auto skill = getDamageTypeSkill(weapon_->damageType());
    const auto damage = damageFromWeapon * skill;

    const auto finalDamageToEnemy = enemy.armor_->takeAndTransferDamage(damage, weapon_->damageType());
    enemy.health_ -= finalDamageToEnemy;
}
void Person::wearArmor(std::unique_ptr<Armor>&& armor)
{
    if (armor)
        armor_.reset(armor.release());
    else
        armor_.reset(new WithoutArmor());
}
void Person::takeWeapon(std::unique_ptr<Weapon>&& weapon)
{
    if (weapon)
        weapon_.reset(weapon.release());
    else
        weapon_.reset(new Fists());
}
const std::string& Person::getName() const
{
    return name_;
}
Points Person::getHealth() const
{
    return health_;
}
Person::~Person()
{
}

// Peasant
Peasant::Peasant(std::string name, Points health):
        Person(name, health)
{
}
Points Peasant::getDamageTypeSkill(DamageType type) const
{
    switch (type)
    {
        case DamageType::Blunt: return 1;
        case DamageType::Slashing: return 0.6;
        case DamageType ::Piercing: return 0.5;
    }
    assert(!"Invalid damage type");
    return 0;
}
std::string Peasant::getJob() const
{
    return "Peasant";
}

// Knight
Knight::Knight(std::string name, Points health):
        Person(name, health)
{
}
Points Knight::getDamageTypeSkill(DamageType type) const
{
    switch (type)
    {
        case DamageType::Blunt: return 1;
        case DamageType::Slashing: return 1;
        case DamageType ::Piercing: return 0.7;
    }
    assert(!"Invalid damage type");
    return 0;
}
std::string Knight::getJob() const
{
    return "Knight";
}

// Archer

Archer::Archer(std::string name, Points health):
        Person(name, health)
{
}
Points Archer::getDamageTypeSkill(DamageType type) const
{
    switch (type)
    {
        case DamageType::Blunt: return 0.8;
        case DamageType::Slashing: return 0.7;
        case DamageType ::Piercing: return 1;
    }
    assert(!"Invalid damage type");
    return 0;
}
std::string Archer::getJob() const
{
    return "Archer";
}