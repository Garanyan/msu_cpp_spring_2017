/**
 * @brief  The class describes the properties of weapon:
 * penetration, speed, range
 */

#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED
#include "../include/armor.h"
#include <string>

using Points = int;
enum class DamageType
{   SWORD,
    BOW,
    HUMMER,
    FIST
};

class Weapon
{
    public:

    Weapon();
    virtual ~Weapon();
     Weapon(const std::string& name, int Range, int Speed, int Penetration);

     void setRange(int);
     void setSpeed(int);
     void setPenetration(int);

     int getRange(void);
     int getSpeed(void);
     int getPenetration(void);

     virtual DamageType getDamageType() const = 0;
     virtual Points getDamage(Armor& armor) const = 0;

    protected:
        DamageType type;
		Points penetration;
		Points speed;
		Points range;
		Points damage;
		Weapon(const Weapon& copied) = delete;
		Weapon& operator=(const Weapon& copied) = delete;
};

class Sword final: public Weapon{
public:
    Sword();
	DamageType getDamageType()const override {
		return type;
	}
	Points getDamage(Armor& armor) const override;
};

class Hammer final: public Weapon{
public:
    Hammer();
	DamageType getDamageType()const override{
		return type;
	}
	Points getDamage(Armor& armor) const override;
};

class Bow final: public Weapon{
public:
    Bow();
	DamageType getDamageType()const override {
		return type;
	}
	Points getDamage(Armor& armor) const override;
};

class Fist final: public Weapon{
public:
    Fist();
	DamageType getDamageType()const override {
		return type;
	}
	Points getDamage(Armor& armor) const override;
};
#endif // WEAPON_H_INCLUDED
