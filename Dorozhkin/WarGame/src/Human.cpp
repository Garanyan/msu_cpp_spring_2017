#include "../include/Human.h"
#include "../include/Weapon.h"
#include "../include/Armor.h"

Human::Human()
{
    name = generatenewname();
    coordinate = "Barrack";
    weapon = Nothing();
    armor = Torso();
}

//default values for Peasant
Peasant::Peasant(int forse = 0, int speed = 0, int skill = 0, int endurance = 0) :
    this->forse(forse), this->speed(speed), this->skill(skill), this->endurance(endurance)
{
    
}

// default values for Archer
Archer::Archer(int forse = 0, int speed = 0, int skill = 0, int endurance = 0) :
    this->forse(forse), this->speed(speed), this->skill(skill), this->endurance(endurance)
{
    
}

// default values for Knight
Knight::Knight(int forse = 0, int speed = 0, int skill = 0, int endurance = 0) :
    this->forse(forse), this->speed(speed), this->skill(skill), this->endurance(endurance)
{
    
}
