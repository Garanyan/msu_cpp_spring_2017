/**
 * @brief The class describes the properties of armor: protection against
 * specific weapons and cost for speed
 */
#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED
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
    virtual ~Armor();
     Armor(const std::string& name, int resistance, int exhaust);
	Armor&
     Armor(const Armor& /*copied*/) = delete;
	 Armor& operator=(const Armor& /*copied*/) = delete;
	 virtual ArmorType getType() const = 0;
    virtual Points getProtection(DamageType damage) const = 0;

     void setExhaust(int);
     void setResistance(int);

     int getExhaust(void);
     Points getResistance(void);

    private:
		ArmorType type;
		Points resistance;
		int exhaust;
};

class FullPlateArmour final: public Armor
{
public:
    FullPlateArmour();
    ArmorType getType() const override
    {
        return ArmorType::type;
    }
    Points getProtection(DamageType damage) const override;
};

class LightSuit final: public Armor
{
public:
    LightSuit();
    ArmorType getType() const override
    {
        return ArmorType::type;
    }
    Points getProtection(DamageType damage) const override;
};

class Naked final: public Armor{
public:
    Naked();
    ArmorType getType() const override
    {
        return ArmorType::type;
    }
    Points getProtection(DamageType damage) const override;
};
#endif // ARMOR_H_INCLUDED
