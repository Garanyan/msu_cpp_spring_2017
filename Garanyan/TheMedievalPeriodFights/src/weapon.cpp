#include "../include/weapon.h"
//#include "../include/armor.h"
#include <assert.h>
Sword ::Sword() : Weapon() {
        type = DamageType::SWORD;
        speed = 100;
        range = 5;
        penetration = 17;
        damage = 70;
}

Hammer::Hammer() : Weapon() {
        type = DamageType::HUMMER;
        speed = 20;
        range = 3;
        penetration = 20;
        damage = 100;
}

Bow::Bow() : Weapon(){
        type = DamageType::BOW;
        speed = 30;
        range = 10;
        penetration = 15;
        damage = 50;
}

Fist::Fist() : Weapon() {
        type = DamageType::FIST;
        speed = 40;
        range = 1;
        penetration = 1;
        damage = 2;
}




Points Hammer::getDamage(Armor& armor)const{
    switch(armor.getType){
    case ArmorType::Unarmored: return damage*2;
    case ArmorType::Chains: return damage + penetration /2;
    case ArmorType::Plates: return damage + penetration;
    }
    assert(!"Invalid armor type");
        return 0;
}

Points Sword::getDamage(Armor& armor)const{
    switch(armor.getType){
    case ArmorType::Unarmored: return damage;
    case ArmorType::Chains: return damage + penetration;
    case ArmorType::Plates: return damage + penetration/3;
    }
    assert(!"Invalid armor type");
        return 0;
}

Points Bow::getDamage(Armor& armor)const{
    switch(armor.getType){
    case ArmorType::Unarmored: return damage;
    case ArmorType::Chains: return damage + penetration /2;
    case ArmorType::Plates: return damage + penetration;
    }
    assert(!"Invalid armor type");
        return 0;
}

Points Fist::getDamage (Armor& armor)const{
    switch(armor.getType){
    case ArmorType::Unarmored: return damage;
    case ArmorType::Chains: return 0;
    case ArmorType::Plates: return 0 ;
    }
    assert(!"Invalid armor type");
        return 0;
}
