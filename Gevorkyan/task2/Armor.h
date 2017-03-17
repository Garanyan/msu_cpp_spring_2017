#ifndef ARMOR_H
#define ARMOR_H
class Armor
{
private:
    int protection_sword;
    int protection_bow;
    int protection_shovel;
    int protection_hammew;
    int speed_;
public:
    Armor(const Armor& copied)=delete;
    Armor& operator=(const Armor& copied)=delete;
};

class Chain : public Armor
{

};

class Shell : public Armor
{

};

#endif // ARMOR_H
