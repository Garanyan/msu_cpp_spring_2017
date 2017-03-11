/**
 * @brief  The class describes the properties of weapon:
 * penetration, speed, range
 */

#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

class weapon
{
    public:
    /**
     * @brief
     * @param
     * @return
     * @throw
     * @throw
     */

     int penetration;
     int speed;
     int range;

     weapon(const std::string& name, int Range, int Speed, int Penetration);

     void setRange(int);
     void setSpeed(int);
     void setPenetration(int);

     int getRange(void);
     int getSpeed(void);
     int getPenetration(void);
    private:
        std::string name;
};

class sword final: public weapon
{

};

class hammer final: public weapon
{

};

class bow final: public weapon
{

};

class shovel final: public weapon
{

};
#endif // WEAPON_H_INCLUDED
