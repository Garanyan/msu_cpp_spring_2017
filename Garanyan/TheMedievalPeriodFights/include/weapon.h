/**
 * @brief  The class describes the properties of weapon:
 * penetration, speed, range
 */

#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED
#include <string>
#include <memory>
//#include "../include/armor.h"

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

        Weapon()=default;
        virtual ~Weapon()=default;
         /*Weapon(const std::string& name, int Range, int Speed, int Penetration);

         void setRange(int);
         void setSpeed(int);
         void setPenetration(int);

         int getRange(void);
         int getSpeed(void);
         int getPenetration(void);*/
		void setDamage(Points);

         virtual DamageType getDamageType() const = 0;
         virtual Points getDamage() const = 0;

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
	Points getDamage() const override;
};

class Hammer final: public Weapon{
public:
    Hammer();
	DamageType getDamageType()const override{
		return type;
	}
	Points getDamage() const override;
};

class Bow final: public Weapon{
public:
    Bow();
	DamageType getDamageType()const override {
		return type;
	}
	Points getDamage() const override;
};

class Fist final: public Weapon{
public:
    Fist();
	DamageType getDamageType()const override {
		return type;
	}
	Points getDamage() const override;
};
#endif // WEAPON_H_INCLUDED
