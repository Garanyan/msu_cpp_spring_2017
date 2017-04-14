#include "weapon.h"

Sword ::Sword(){
        type = SWORD;
        speed = 100;
        range = 5;
        penetration = 17;
        damage = 70;
}

Hammer::Hammer(){
        type = HAMMER;
        speed = 20;
        range = 3;
        penetration = 20;
        damage = 100;
}

Bow::Bow(){
        type = BOW;
        speed = 30;
        range = 10;
        penetration = 15;
        damage = 50;
}

DamageType Weapon::getDamageType()const override {
    return type;
}

Points Hammer::getDamage(armor &enemyArmor){
    switch(enemyArmor.get_type()){
    case ArmorType::Unarmored: return damage*2;
    case ArmorType::Chains: return damage - enemyArmor.getResistsnce/2;
    case ArmorType::Plates: return damage - enemyArmor.getResistance ;
    }
    assert(!"Invalid armor type");
        return 0;
}

Points Sword::getDamage(armor &enemyArmor){
    switch(enemyArmor.get_type()){
    case ArmorType::Unarmored: return damage;
    case ArmorType::Chains: return damage - enemyArmor.getResistsnce;
    case ArmorType::Plates: return damage - enemyArmor.getResistance/3 ;
    }
    assert(!"Invalid armor type");
        return 0;
}

Points Bow::getDamage(armor &enemyArmor){
    switch(enemyArmor.get_type()){
    case ArmorType::Unarmored: return damage;
    case ArmorType::Chains: return damage - enemyArmor.getResistsnce/2;
    case ArmorType::Plates: return damage - enemyArmor.getResistance ;
    }
    assert(!"Invalid armor type");
        return 0;
}
