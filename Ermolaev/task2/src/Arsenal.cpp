#include "Arsenal.h"

// Arsenal
std::unique_ptr<Weapon> Arsenal::getWeapon(){
    if (weapons_.empty())
        return std::unique_ptr<Weapon>();

    auto weapon = std::move(weapons_.back());
    weapons_.pop_back();
    return weapon;
}
std::unique_ptr<Armor> Arsenal::getArmor(){
    if(armors_.empty())
        return std::unique_ptr<Armor>();

    auto armor = std::move(armors_.back());
    armors_.pop_back();
    return armor;
}
void Arsenal::putArmor(std::unique_ptr<Armor>&& armor)
{
    armors_.push_back(std::move(armor));
}
void Arsenal::putWeapon(std::unique_ptr<Weapon>&& weapon)
{
    weapons_.push_back(std::move(weapon));
}
void Arsenal::addRandomArmor()
{
    srand(std::clock());
    int r = std::rand() % 2;
    switch (r)
    {
        case 0: armors_.push_back(make<Chains>());break;
        case 1: armors_.push_back(make<Plates>());break;
    }
}
void Arsenal::addRandomWeapon()
{
    srand(std::clock());
    int r = std::rand() % 2;
    switch (r)
    {
        case 0: weapons_.push_back(make<Sword>());break;
        case 1: weapons_.push_back(make<Bow>());break;
    }
}
template <class T>
std::unique_ptr<T> Arsenal::make()
{
    return std::unique_ptr<T>(new T());
}