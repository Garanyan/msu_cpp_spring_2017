#ifndef WEAPON_H
#define WEAPON_H
class Weapon
{
private:
    int piercing_chain;
    int piercing_shell;
    int speed_weapon;
    int range;
public:
    Weapon(const Weapon& copied)=delete;
    Weapon& operator=(const Weapon& copied)=delete;
};

class Sword : public Weapon
{

};

class Bow : public Weapon
{

};

class Shovel : public Weapon
{

};

class Hammer : public Weapon
{

};

#endif// WEAPON_H
