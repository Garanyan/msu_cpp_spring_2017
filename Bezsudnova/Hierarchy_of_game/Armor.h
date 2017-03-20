#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED

class QArmor
{
    public:
        int protectionFromHammer; //молот
        int protectionFromShovel; //лопата
        int protectionFromSword; // меч
        int protectionFromBow; //лук
        int mulctOfSpeed; // штраф за скорость

};

class Plate: public QArmor //латы
{
    void create()
    {
        protectionFromHammer=0; //молот
        protectionFromShovel=0; //лопата
        protectionFromSword=0; // меч
        protectionFromBow=0; //лук
        mulctOfSpeed=0; //

    }

};

class Panoply: public Qarmor //доспехи
{
    void create()
    {
        protectionFromHammer=0; //молот
        protectionFromShovel=0; //лопата
        protectionFromSword=0; // меч
        protectionFromBow=0; //лук
        mulctOfSpeed=0; //

    }


};


#endif // ARMOR_H_INCLUDED
