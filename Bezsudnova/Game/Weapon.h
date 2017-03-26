#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

class  Weapon
{
public:
    int powerWeapon;
    int speedWeapon;
    int distanceWeapon;

    Weapon()
    {
        powerWeapon = 0;
        speedWeapon = 0;
        distanceWeapon = 0;
    }

};



class Shovel: public Weapon   //лопата
{
public:
    Shovel()
    {
        powerWeapon = 0;
        speedWeapon = 0;
        distanceWeapon = 0;
    }

};

class Sword: public Weapon
{
public:
    Sword()
    {
        powerWeapon = 0;
        speedWeapon = 0;
        distanceWeapon = 0;
    }

};



class Hammer: public Weapon
{
public:
    Hammer()
    {
        powerWeapon = 0;
        speedWeapon = 0;
        distanceWeapon = 0;
    }

};



class Bow: public Weapon
{
public:
    Bow()
    {
        powerWeapon = 0;
        speedWeapon = 0;
        distanceWeapon = 0;
    }

};

#endif // WEAPON_H_INCLUDED
