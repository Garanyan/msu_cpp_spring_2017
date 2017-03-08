/**
 * @brief  The class describes characters, types of characters,
 * their skills (HP,Strength, Speed, weapon mastery, agility, luck)
 */
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

class person
{
    public:
    /**
     * @brief
     * @param
     * @return
     * @throw
     * @throw
     */

     int healthPoints;
     int strength;
     int speed;
     int weaponMastery;
     int agility;
     int luck;
};

class knight final: public person
{

};

class peasant final: public person
{

};
class sharp final: public person
{

};

#endif // PERSON_H_INCLUDED
