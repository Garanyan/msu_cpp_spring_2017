#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

class QWeapon
{
    public:
        int penetrationPowerForPlate;
        int penetrationPowerForPanoply;
        int speedPenalty;
};


class Hammer: public QWeapon//�����
{
    penetrationPowerForPlate=0;
    penetrationPowerForPanoply=0;
    speedPenalty=0;

};

class Shovel: public QWeapon //������
{
    penetrationPowerForPlate=0;
    penetrationPowerForPanoply=0;
    speedPenalty=0;
};

class Sword: public QWeapon // ���
{
    penetrationPowerForPlate=0;
    penetrationPowerForPanoply=0;
    speedPenalty=0;
};

class Bow: public QWeapon // ����� �� ��������
{
    penetrationPowerForPlate=0;
    penetrationPowerForPanoply=0;
    speedPenalty=0;
};




#endif // WEAPON_H_INCLUDED
