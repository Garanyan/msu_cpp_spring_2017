#include "stdafx.h"

#include "../include/units/knight.h"

Arena::Knight::Knight(const std::string& name)
    : UnitImpl<Details::KnightTraits>(name)
{
}

Arena::Knight::~Knight()
{
}
