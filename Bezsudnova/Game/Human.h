#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

class Human
{

public:
    string name;
    int power;
    int speed;
    int skill;
    int endurance;
    int  *takenArmor;
    int  *takenWeapon;

    Human()
    {
        name = "Peter";
        power = 0;
        speed = 0;
        skill = 0;
        endurance = 0;
    }

    template<class T>
    void takenArmor()
    {
        T newArmor;
        *takenArmor = &newArmor;

    }

    template<class T>
    void takenWeapon()
    {
        T newWeapon;
        *takenWeapon = &newWeapon;

    }

};

class Archer: public Human // Лучник
{
public:
        Archer(string date_name)
        {
            name = date_name;
            power = 0;
            speed = 0;
            skill = 0;
            endurance = 0;
        }
};

class Peasant: public Human
{
public:
        Peasant(string date_name)
        {
            name = date_name;
            power = 0;
            speed = 0;
            skill = 0;
            endurance = 0;
        }
};

class Knight: public Human
{
public:
        Knight(string date_name)
        {
            name = date_name;
            power = 0;
            speed = 0;
            skill = 0;
            endurance = 0;
        }
};

#endif // HUMAN_H_INCLUDED
