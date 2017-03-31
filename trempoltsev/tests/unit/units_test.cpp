#include "stdafx.h"

#include "../include/units/archer.h"
#include "../include/units/knight.h"
#include "../include/units/peasant.h"

using namespace Arena;

TEST(UnitsTest, TestArcher)
{
    Archer archer("Tom");
}

TEST(UnitsTest, TestKnight)
{
    Knight knight("Jack");
}

TEST(UnitsTest, TestPeasant)
{
    Peasant peasant("Bob");
}
