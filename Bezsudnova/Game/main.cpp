#include <iostream>
#include <string>

using namespace std;

#include "Armor.h"
#include "Weapon.h"
#include "Human.h"

int main()
{
    string small;
    cin >> small;
    Knight Bob(small);
    //Bob.abilityTakeArmor<Lats>();
    cout << Bob.skill;

    return 0;
}
