#pragma once
#include <map>
#include "armor.h"

class Arsenal{
private:
    std::map<ArmorType, int> armory;
    std::unique_ptr <Armor> createLats();
    std::unique_ptr <Armor> createCorslet();

public:
    Arsenal();
    ~Arsenal() = default;
    bool anyLats();
    bool anyCorslet();
    std::unique_ptr <Armor> useLats();
    std::unique_ptr <Armor> useCorslet();
};
