
#include "armor.h"
#include <assert.h>
#include "../include/weapon.h"

void Armor::setExhaust(Points x) {
	if(exhaust!=0)
		exhaust = x;
}

void Armor::setResistance(Points x) {
	if(resistance!=0)
		resistance = x;
}

FullPlateArmor::FullPlateArmor() : Armor(){
    resistance = 5;
    exhaust = 2;
}

Points FullPlateArmor::getProtection(DamageType damage) const {
        switch (damage)
        {
            case DamageType::HUMMER: return 100/resistance - 10;
            case DamageType::SWORD: return 200/resistance - 5;
            case DamageType::BOW: return 50/resistance;
			case DamageType::FIST: return 0;
        }
        assert(!"Invalid damage type");
        return 0;
}

LightSuit::LightSuit() : Armor(){
    resistance = 3;
    exhaust = 10;
}

Points LightSuit::getProtection(DamageType damage) const {
        switch (damage)
        {
            case DamageType::HUMMER: return 100/resistance ;
            case DamageType::SWORD: return 100/resistance - 10;
            case DamageType::BOW: return 20;
			case DamageType::FIST: return 5;
        }
        assert(!"Invalid damage type");
        return 0;
}

Naked::Naked() : Armor(){
    resistance = 0;
    exhaust = 0;
}

Points Naked::getProtection(DamageType dmg) const {
        switch (dmg)
        {
            case DamageType::HUMMER: return 70;
            case DamageType::SWORD: return 50;
            case DamageType::BOW: return 40;
			case DamageType::FIST: return 20;
        }
        assert(!"Invalid damage type");
        return 0;
}
