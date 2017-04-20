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

Bow::Bow(){
        type = FIST;
        speed = 40;
        range = 1;
        penetration = 1;
        damage = 2;
}


DamageType Weapon::getDamageType()const override {
    return type;
}

Points Hammer::getDamage(Armor &enemyArmor){
    switch(enemyArmor.get_type()){
    case ArmorType::Unarmored: return damage*2;
    case ArmorType::Chains: return damage - enemyArmor.getResistsnce/2;
    case ArmorType::Plates: return damage - enemyArmor.getResistance ;
    }
    assert(!"Invalid armor type");
        return 0;
}

Points Sword::getDamage(Armor &enemyArmor){
    switch(enemyArmor.get_type()){
    case ArmorType::Unarmored: return damage;
    case ArmorType::Chains: return damage - enemyArmor.getResistsnce;
    case ArmorType::Plates: return damage - enemyArmor.getResistance/3 ;
    }
    assert(!"Invalid armor type");
        return 0;
}

Points Bow::getDamage(Armor &enemyArmor){
    switch(enemyArmor.get_type()){
    case ArmorType::Unarmored: return damage;
    case ArmorType::Chains: return damage - enemyArmor.getResistsnce/2;
    case ArmorType::Plates: return damage - enemyArmor.getResistance ;
    }
    assert(!"Invalid armor type");
        return 0;
}

Points Fist::getDamage(Armor &enemyArmor){
    switch(enemyArmor.get_type()){
    case ArmorType::Unarmored: return damage;
    case ArmorType::Chains: return 0;
    case ArmorType::Plates: return 0 ;
    }
    assert(!"Invalid armor type");
        return 0;
}
