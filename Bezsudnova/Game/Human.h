#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDE D


class Human
{

public:
    string name;
    int power;
    int speed;
    int skill;
    int endurance;
    Armor  *takenArmor;
    Weapon  *takenWeapon;

    Human()
    {
        name = "Peter";
        power = 0;
        speed = 0;
        skill = 0;
        endurance = 0;
    }



    template<class T>
    void abilityTakeArmor()
    {
        T newArmor;
        *takenArmor = &newArmor;
        return ;

    };

    template<class T>
    void abilityTakeWeapon()
    {
        T newWeapon;
        *takenWeapon = &newWeapon;
        return ;
    };

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
