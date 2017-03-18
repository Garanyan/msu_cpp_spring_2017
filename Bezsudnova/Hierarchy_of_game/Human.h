#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

class QHuman()
{
    public:
        int power;
        float speed;
        int endurance;
        int fightSkil;


        void takeArmor() {}   // need_to_write
        void takeWeapon(){}   // need_to_write
        void takeDamage(){}   // need_to_write
        // composition
    private:
        QArmor bronia;
        QWeapon oryshie;

}


class Peasant:public QHuman //крестьянин
{

    void create()
    {
        power=1;
        speed=1;
        endurance=3;
        fightSkil=0
    }
}



class Knight:public QHuman // рыцарь
{
    void create()
    {
        power=1;
        speed=3;
        endurance=1;
        fightSkil=0;
    }
}




class Archer:public QHuman   // лучник
{
    void create()
    {
        power=1;
        speed=2;
        endurance=2;
        fightSkil=0;
    }
}

#endif // HUMAN_H_INCLUDED
