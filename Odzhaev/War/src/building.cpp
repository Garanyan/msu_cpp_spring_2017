
#include <vector>
#include "../include/building.h"
//#include "armor.h"
//#include "weapon.h"
//#include "arsenal.h"
//#include "human.h"


//Building
void Building::enter(std::unique_ptr<Human> new_warrior)
{
	warriors.push_back(std::move(new_warrior));
}
std::unique_ptr<Human> Building::exit()
{
	std::unique_ptr<Human> new_warrior(std::move(warriors.back()));
	warriors.pop_back();
	return new_warrior;
}
void Building::state()
{
	for(auto it = warriors.begin(); it != warriors.end(); it++) {
		switch((*it)->getType()) {
			case HumanType::HUMAN:
				std::cout<<"Human ";
				break;
			case HumanType::PEASANT:
				std::cout<<"Peasant ";
				break;
			case HumanType::KNIGHT:
				std::cout<<"Knight ";
				break;
			case HumanType::ARCHER:
				std::cout<<"Archer ";
				break;
			default:
				std::cout<<"Error ";

		}	
		std::cout<<(*it)->getName()<<std::endl;
	}		
}

//Barack
std::vector<std::unique_ptr<Human>> Barack::getWarrior(const int& number)
{
	std::vector<std::unique_ptr<Human>> men;
	for(int i = 0; i < number; i++) {	
		men.push_back(std::move(warriors.back()));
		warriors.pop_back();
	}
	return men;
}
void Barack::createWarriors()
{
	for(int i = 0; i < 6; i++) {	
		warriors.push_back(std::unique_ptr<Human>(new Peasant("joht"+ std::to_string(i))));
		warriors.push_back(std::unique_ptr<Human>(new Knight("tom"+ std::to_string(i))));
		warriors.push_back(std::unique_ptr<Human>(new Archer("pol"+ std::to_string(i))));
	}
}

//Arena
std::unique_ptr<Human> Arena::fight(std::unique_ptr<Human> human1, std::unique_ptr<Human> human2) 
{
	std::unique_ptr<Human> winner;
	int num = 0;
	while(true && num<100) {
		human1->attack(*human2);
		if(human2->getHealth()<=0) {
			winner = std::move(human1);
			break;
		}
		human2->attack(*human1);
		if(human1->getHealth()<=0) {
			winner = std::move(human2);
			break;
		}
	}
	return winner;
}

std::unique_ptr<Human> Arena::battle()
{
	while(warriors.size()>1) {
		std::unique_ptr<Human> human1(std::move(warriors.back()));
		warriors.pop_back();
		std::unique_ptr<Human> human2(std::move(warriors.back()));
		warriors.pop_back();
		warriors.push_back(fight(std::move(human1),std::move(human2)));
	}
	std::unique_ptr<Human> winner(std::move(warriors.back()));
	warriors.clear();
	return winner;
}
