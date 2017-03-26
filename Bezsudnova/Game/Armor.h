#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED

class  Armor
{
public:
    int defence;
    int fineForSpeed;

    Armor()
    {
        defence=0;
        fineForSpeed=0;
    }

};



class Lats: public Armor
{
public:
    Lats()
    {
        defence=0;
        fineForSpeed=0;
    }

};

class Chain-mail: public Armor
{
public:
    Chain-mail()
    {
        defence=0;
        fineForSpeed=0;
    }

};



#endif // ARMOR_H_INCLUDED
