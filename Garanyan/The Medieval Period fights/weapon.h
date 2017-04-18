/**
 * @brief  The class describes the properties of weapon:
 * penetration, speed, range
 */

#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED
using Points = int;
enum class DamageType
{   SWORD,
    BOW,
    HUMMER
};
class Weapon
{
    public:

    Weapon();
    virtual ~Weapon();
     Weapon(const std::string& name, int Range, int Speed, int Penetration);

     Weapon(const Weapon& copied) = delete;
	 Weapon& operator=(const Weapon& copied) = delete;


     void setRange(int);
     void setSpeed(int);
     void setPenetration(int);

     int getRange(void);
     int getSpeed(void);
     int getPenetration(void);

     virtual DamageType getDamageType() const = 0;
     virtual Points getDamage(armor &enemyArmor) const = 0;
    private:
        DamageType type;
		Points penetration;
		Points speed;
		Points range;
		Points damage;
};

struct BowTraits
{
    using Type = PiercingDamage;
    static constexpr Point damage = 20;
};


template <class WeaponTraits, class ArmorTraits>
Point getDamage(const WeaponImpl<WeaponTraits>&, const ArmorImpl<ArmorTraist>&)
{
    const auto protection = ArmorTraits::protection(typename WeaponTraits::Type());
    const auto damage = WeaponTraits::damage();
    return protection-damage;
}

class Sword final: public Weapon
{
    Sword();


};

class Hammer final: public Weapon
{
    Hammer();
};

class Bow final: public Weapon
{
    Bow();
};

class shovel final: public weapon
{

};
#endif // WEAPON_H_INCLUDED
