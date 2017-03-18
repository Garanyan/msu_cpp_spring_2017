#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

class QWeapon
{
    public:
        int penetrationPowerForPlate;
        int penetrationPowerForPanoply;
        int speedPenalty;
};


class Hammer: public QWeapon//молот
{
    penetrationPowerForPlate=0;
    penetrationPowerForPanoply=0;
    speedPenalty=0;

};

class Shovel: public QWeapon //лопата
{
    penetrationPowerForPlate=0;
    penetrationPowerForPanoply=0;
    speedPenalty=0;
};

class Sword: public QWeapon // меч
{
    penetrationPowerForPlate=0;
    penetrationPowerForPanoply=0;
    speedPenalty=0;
};

class Bow: public QWeapon // штраф за скорость
{
    penetrationPowerForPlate=0;
    penetrationPowerForPanoply=0;
    speedPenalty=0;
};




#endif // WEAPON_H_INCLUDED
