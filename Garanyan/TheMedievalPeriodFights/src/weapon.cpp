#include "../include/weapon.h"
#include "../include/armor.h"
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




Points Hammer::getDamage()const {
	return damage / 2 + speed / 3;
}

Points Sword::getDamage()const {
    return damage + penetration / 3;
}

Points Bow::getDamage()const {
	
	return damage + range / 2;
}

Points Fist::getDamage()const{

	return 5;
}

void Weapon::setDamage(Points x){
	damage = x;
}
