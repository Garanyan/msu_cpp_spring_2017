#ifndef WEAPON_H
#define WEAPON_H

class Character;

class Weapon
{
public:
    unsigned rate;
    unsigned distance;
    unsigned damage;
    void fire(Character &c);
    bool setHolder(Character &c);
    bool setHolder();
private:
    virtual unsigned damageMultiplier(unsigned damage);
    Character *holder;
};

#endif