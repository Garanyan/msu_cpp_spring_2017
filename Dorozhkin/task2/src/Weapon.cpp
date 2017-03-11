#include "../include/Weapon.h"

//default values for Nothing
Nothing::Nothing(int radius = 0, int speed = 0) :
    this->radius(radius), this->speed(speed)
{
}

//default values for Sword
Sword::Sword(int radius = 0, int speed = 0) :
    this->radius(radius), this->speed(speed)
{
}

//default values for Shovel
Shovel::Shovel(int radius = 0, int speed = 0) :
    this->radius(radius), this->speed(speed)
{
}

//default values for Bow
Bow::Bow(int radius = 0, int speed = 0) :
    this->radius(radius), this->speed(speed)
{
}

//default values for Hammer
Hammer::Hammer(int radius = 0, int speed = 0) :
    this->radius(radius), this->speed(speed)
{
}
