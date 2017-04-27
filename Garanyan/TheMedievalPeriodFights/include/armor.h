/**
 * @brief The class describes the properties of armor: protection against
 * specific weapons and cost for speed
 */
#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED
#include "../include/weapon.h"
#include <string>
using Points = int;

enum class ArmorType
{
    Unarmored,
    Chains,
    Plates
};

class Armor
{
    public:
    Armor(){};
    virtual ~Armor()=default;
    // Armor(const std::string& name, int resistance, int exhaust);
     Armor(const Armor& /*copied*/) = delete;
	 Armor& operator=(const Armor& /*copied*/) = delete;
	 virtual ArmorType getType() const = 0;
    virtual Points getProtection(DamageType ) const = 0;
/*
     void setExhaust(int);
     void setResistance(int);

     int getExhaust(void);
     Points getResistance(void);
*/
    protected:
		ArmorType type;
		Points resistance;
		int exhaust;
};

class FullPlateArmor final: public Armor
{
public:
    FullPlateArmor();
    ArmorType getType() const override
    {
        return type;
    }
    Points getProtection(DamageType) const override;
};

class LightSuit final: public Armor
{
public:
    LightSuit();
    ArmorType getType() const override
    {
        return type;
    }
    Points getProtection(DamageType) const override;
};

class Naked final: public Armor{
public:
    Naked();
    ArmorType getType() const override
    {
        return type;
    }
    Points getProtection(DamageType dmg ) const override;
};
#endif // ARMOR_H_INCLUDED
