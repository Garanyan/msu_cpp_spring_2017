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
};

class fullPlateArmour final: public armor
{

};

class lightSuit final: public armor
{

};
#endif // ARMOR_H_INCLUDED
