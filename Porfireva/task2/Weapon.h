
class Weapon
{
    double w_distance;
    double w_speed;
    double penetration_hauberk;
    double penetration_corslet;
    Weapon(const Armor& copied) = delete;
    Weapon& operator=(const Weapon& copied) = delete;
};

class Sword final: public Weapon
{
};

class Bow final: public Weapon
{
};

class Shovel final: public Weapon
{
};

class Hammer final: public Weapon
{
};
