#pragma once

class Weapon;

class Armor {
    int speedpenalty;
public:
    int countbonus(Weapon &w);
};

class Torso : public Armor {
    
};

class Chain : public Armor {
    
};

class Corslet : public Armor {
    
};
