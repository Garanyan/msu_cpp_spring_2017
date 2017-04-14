
#include "armor.h"

FullPlateArmour::FullPlateArmour() : Armor{
    type = Plates;
    resistance = 50;
    exhaust = 20;
}

Points FullPlateArmor::getProtection(DamageType damage) const override{
        switch (damage)
        {
            case DamageType::HUMMER: return resistance - 10;
            case DamageType::SWORD: return resistance - 5;
            case DamageType::BOW: return resistance;
        }
        assert(!"Invalid damage type");
        return 0;
}

LightSuit::LightSuit() : Armor{
    type = Chains;
    resistance = 30;
    exhaust = 10;
}

Points LightSuit::getProtection(DamageType damage) const override{
        switch (damage)
        {
            case DamageType::HUMMER: return resistance ;
            case DamageType::SWORD: return resistance - 10;
            case DamageType::BOW: return 10;
        }
        assert(!"Invalid damage type");
        return 0;
}

Naked::Naked() : Armor{
    type = Unarmored;
    resistance = 0;
    exhaust = 0;
}

Points Naked::getProtection(DamageType damage) const override{
        switch (damage)
        {
            case DamageType::HUMMER: return resistance;
            case DamageType::SWORD: return resistance;
            case DamageType::BOW: return resistance;
        }
        assert(!"Invalid damage type");
        return 0;
}
