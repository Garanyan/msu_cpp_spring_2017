#include "stdafx.h"

#include "../include/units/archer.h"

Arena::Archer::Archer(const std::string& name)
    : UnitImpl<Details::ArcherTraits>(name)
{
}

Arena::Archer::~Archer()
{
}
