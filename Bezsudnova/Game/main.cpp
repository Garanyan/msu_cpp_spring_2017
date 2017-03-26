#include <iostream>
#include <string>

using namespace std;





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


class Weapon
{
public:
    int power;
};








int main()
{
    string small;
    cin >> small;
    Lyshic Bob(small);
    Bob.takenArmor<Lats>();


    return 0;
}
