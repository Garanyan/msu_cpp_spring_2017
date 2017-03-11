#ifndef ARMOR_H
#define ARMOR_H

class Character;

class Armor
{
public:
    unsigned strength;
    unsigned speedPenalty;
    unsigned receiveDamage(unsigned damage);
    bool setWearer(Character &character);
    bool setWearer();
private:
    Character *wearer;
};

#endif