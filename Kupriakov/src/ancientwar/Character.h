#ifndef CHARACTER_H
#define CHARACTER_H

class Armor;
class Weapon;

class Character
{
public:
    unsigned strength;
    unsigned endurance;
    unsigned speed;
    unsigned weaponSkill;
    void onDamageReceived(unsigned damage);
    bool grabWeapon(Weapon &weapon);
    bool wearArmor(Armor &armor);
private:
    Weapon *currentWeapon;
    Armor *currentArmor;
};

#endif