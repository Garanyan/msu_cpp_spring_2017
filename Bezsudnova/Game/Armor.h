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

    Armor(const Armor& copied) = delete;
	Armor& operator=(const Armor& copied) = delete;

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

class ChainMail: public Armor
{
public:
    ChainMail()
    {
        defence=0;
        fineForSpeed=0;
    }

};



#endif // ARMOR_H_INCLUDED
