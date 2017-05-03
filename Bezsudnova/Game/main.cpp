#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_map>
#include <memory>
#include <stdlib.h>
#include <time.h>


using namespace std;

enum class WeaponType
{
    Sword,
    Hammer,
    Shovel,
    Bow

};

enum class ArmorType
{
    Chain,
    Lats
};

enum class  UnitType
{
    Peasant,
    Archer,
    Knight
};

#include "Armor.h"
#include "Weapon.h"
#include "Units.h"
#include "Barak.h"
#include "Arena.h"
#include "Arsenal.h"


int main()
{

	Barak barak1;
    barak1.createUnits();
    barak1.createUnits();
    Arsenal arsenal1;
    arsenal1.generateWeapon(5);
    arsenal1.generateArmor(5);

    string name;
    cout << "Who goes to Arena? Write his name: ";
    cin >> name;
    std::unique_ptr<Units> person = barak1.goToMain(name);
    person -> weapon_ = arsenal1.getWeapon();
    person -> armor_ = arsenal1.getArmor();

    cout << "Who goes to Arena? Write his name: ";
    cin >> name;
    std::unique_ptr<Units> person1 = barak1.goToMain(name);
    person1 -> weapon_ = arsenal1.getWeapon();
    person1 -> armor_ = arsenal1.getArmor();

    Arena arena1;

    arena1.Fight(std::move(person1),std::move(person),&barak1);

	cout<< "END..." << endl;
}
