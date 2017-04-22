#pragma once
using Points = int;
using kg = double;

enum class ArmorType{
    Corslet,
    Lats,
};

class Armor
{
protected:
    kg ArmorWeigth;
    ArmorType Type;
    
public:
    Armor()= default;
    ~Armor() = default;
    virtual kg getArmorWeigth() const = 0;
    virtual ArmorType getArmorType() const = 0;
    Armor(Armor const&) = delete;
    Armor& operator= (Armor const&) = delete;
};

class Corslet
:public Armor
{
public:
    Corslet();
    kg getArmorWeigth() const override;
    ArmorType getArmorType()const override;
};

class Lats
:public Armor
{
public:
    Lats();
    kg getArmorWeigth() const override;
    ArmorType getArmorType()const override;
};
