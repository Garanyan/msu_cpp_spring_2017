/**
 * @brief The class describes the properties of armor: protection against
 * specific weapons and cost for speed
 */
#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED


class armor
{
    public:
    /**
     * @brief
     * @param
     * @return
     * @throw
     * @throw
     */
     int resistance;
     int exhaust;

     armor(const std::string& name, int resistance, int exhaust);

     void setExhaust(int);
     void setResistance(int);

     int getExhaust(void);
     int getResistance(void);

    private:
        std:string name;
};

class fullPlateArmour final: public armor
{

};

class lightSuit final: public armor
{

};
#endif // ARMOR_H_INCLUDED
