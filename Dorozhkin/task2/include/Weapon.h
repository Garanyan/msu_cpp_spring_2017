#pragma once

class Armor;

class Weapon {
    int radius;
    int speed;
public:
    int countbonus(Armor &a);
};

class Nothing : public Weapon {
    
};

class Sword : public Weapon {
    
};

class Shovel : public Weapon {
    
};

class Bow : public Weapon {
    
};

class Hammer : public Weapon {
    
};
