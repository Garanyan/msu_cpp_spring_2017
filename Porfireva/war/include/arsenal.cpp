#include "arsenal.h"


Arsenal::Arsenal()
{
    armory[ArmorType::Lats] = 5;
}/*
Arsenal::~Arsenal()
{
}*/

std::unique_ptr <Armor> Arsenal::createLats()
{
    return std::unique_ptr<Lats>(new Lats());;
}
std::unique_ptr <Armor> Arsenal::createCorslet()
{
    return std::unique_ptr<Corslet>(new Corslet());;
}
bool Arsenal::anyLats() 
{
    return armory.find(ArmorType::Lats)->second > 0;
}
bool Arsenal::anyCorslet()
{
    return armory.find(ArmorType::Corslet)->second > 0;
}

std::unique_ptr <Armor> Arsenal::useLats()
{
    armory[ArmorType::Lats] -= 1;
    return createLats();
}
std::unique_ptr <Armor> Arsenal::useCorslet()
{
    armory[ArmorType::Corslet] -= 1;
    return createCorslet();
}
