
#include "armor.h"
#include <assert.h>


FullPlateArmor::FullPlateArmor() : Armor(){
	type = ArmorType::Plates;
    resistance = 50;
    exhaust = 20;
}

Points FullPlateArmor::getProtection(Weapon& damage) const {
        switch (damage.getDamageType)
        {
            case DamageType::HUMMER: return resistance - 10;
            case DamageType::SWORD: return resistance - 5;
            case DamageType::BOW: return resistance;
        }
        assert(!"Invalid damage type");
        return 0;
}

LightSuit::LightSuit() : Armor(){
    type = ArmorType::Chains;
    resistance = 30;
    exhaust = 10;
}

Points LightSuit::getProtection(Weapon& damage) const {
        switch (damage.getDamageType)
        {
            case DamageType::HUMMER: return resistance ;
            case DamageType::SWORD: return resistance - 10;
            case DamageType::BOW: return 10;
        }
        assert(!"Invalid damage type");
        return 0;
}

Naked::Naked() : Armor(){
    type = ArmorType::Unarmored;
    resistance = 0;
    exhaust = 0;
}

Points Naked::getProtection(Weapon& dmg) const {
        switch (dmg.getDamageType)
        {
            case DamageType::HUMMER: return resistance;
            case DamageType::SWORD: return resistance;
            case DamageType::BOW: return resistance;
        }
        assert(!"Invalid damage type");
        return 0;
}
