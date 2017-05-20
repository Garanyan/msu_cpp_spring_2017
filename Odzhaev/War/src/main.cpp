#include "stdafx.h"

#include "../include/weapon.h"
#include "../include/armor.h"
#include "../include/human.h"
#include "../include/arsenal.h"
#include "../include/building.h"


int main(int argc, char** argv)
{
	std::cout<<"hi\n";
	

	Arsenal arsenal;
	arsenal.createWeapons();
	arsenal.createArmors();
	arsenal.state();

	std::cout<<"\n\n\n";
	Barack barack;
	barack.createWarriors();
	barack.state();
	
	Arena arena1;
	for(int i = 0; i < 4; i++)
	{
		std::unique_ptr<Human> human(barack.exit());
		arsenal.equip(human);
		arena1.enter(std::move(human));
	}
	std::cout<<"\n\n\n";
	arena1.state();
	std::unique_ptr<Human> win1(arena1.battle());
	std::cout<<"Winner1: "<<win1->getName()<<"\n\n\n";
	std::cout<<"Barack\n";
	barack.state();

	return EXIT_SUCCESS;
}
