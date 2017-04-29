#pragma once
using Points = double;
using kg = double;

enum class ArmorType{
    Corslet,
    Lats,
    WithoutArmor,
};

class Armor
{
protected:
    kg ArmorWeigth;
    ArmorType Type;
    
public:
    Armor()=default;
    virtual ~Armor() = 0;
    kg getArmorWeigth() const;
    ArmorType getArmorType() const ;
    Armor(Armor const&) = delete;
    Armor& operator= (Armor const&) = delete;
};

class Corslet
:public Armor
{
public:
    Corslet();
    int getTestValue() { return 5; }
    //kg getArmorWeigth() const override;
   // ArmorType getArmorType()const override;
};

class Lats
:public Armor
{
public:
    Lats();
    //kg getArmorWeigth() const override;
    //ArmorType getArmorType()const override;
};
class WithoutArmor
:public Armor
{
public:
    WithoutArmor();
    //kg getArmorWeigth() const override;
    // ArmorType getArmorType()const override;
};
