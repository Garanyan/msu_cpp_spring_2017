#include "stdafx.h"

#include "../include/units/peasant.h"

Arena::Peasant::Peasant(const std::string& name)
    : UnitImpl<Details::PeasantTraits>(name)
{
}

Arena::Peasant::~Peasant()
{
}
