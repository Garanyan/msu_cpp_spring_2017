#include "Armor.h"
#include "Weapon.h"
#include "Person.h"

#include "Arsenal.h"
#include "Barack.h"
#include "Arena.h"

#include "Semaphore.h"

#include "stdafx.h"
#include "utils.h"

Semaphore barackSemaphore(1);
Semaphore arsenalSemaphore(1);
Semaphore queueSemaphore(1);

Arsenal arsenal;
Barack barack;
Arena arena;

void getPersonReady()
{
    while(true)
    {
        barackSemaphore.enter();
        auto unit = barack.callRandPerson();
        barackSemaphore.leave();
        if(unit == nullptr)
            return;

        arsenalSemaphore.enter();
        unit->takeWeapon(arsenal.getWeapon());
        unit->wearArmor(arsenal.getArmor());
        arsenalSemaphore.leave();


        queueSemaphore.enter();
        if(showInfo)
            unit->printStats();
        arena.addToFighters(std::move(unit));
        queueSemaphore.leave();
    }
}

int main(){

    for (int i = 0; i < 15; ++i) {
        arsenal.addRandomArmor();
        arsenal.addRandomWeapon();
    }

    for (int j = 0; j < 32; ++j) {
        std::string name = "test" + std::to_string(j);
        barack.addRandomPerson(name);
    }

    std::thread t1(getPersonReady);
    std::thread t2(getPersonReady);
    std::thread t3(getPersonReady);
    std::thread t4(getPersonReady);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    auto winner = arena.fightsNet();
    std::cout << "winner: ";
    winner->printStats();

    return 0;
}

