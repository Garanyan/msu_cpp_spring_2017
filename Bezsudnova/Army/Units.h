#pragma once

struct Unit
{
    Type typeUnit;
};

struct UInfantry : public Unit
{
    UInfantry ()
    {
        typeUnit = Type::Infantry;
    }
};


struct UArcher : public Unit
{
    UArcher ()
    {
        typeUnit = Type::Archer;
    }
};


struct UHorseman : public Unit
{
    UHorseman()
    {
        typeUnit = Type::Horseman;
    }
};
