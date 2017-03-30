
class Hero{
    protected:
        double power;
        double stamina;
        double speed;
        double Rating;
        double Score;
    public:
        virtual Hero();
        virtual bool GetWeapon();
        virtual void DropWeapon();
        virtual void PutOnArmor();
        Hero(const Hero& copied) = delete;
        Hero& operator=(const Hero& copied) = delete;
        double GetRating();
        double GetScore();
};

class Knight final: public Hero
{
};

class Plowman final: public Hero
{
};

class Archer final: public Hero
{
};
