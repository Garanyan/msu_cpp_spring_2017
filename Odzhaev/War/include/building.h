#pragma once

//#include "../include/weapon.h"
//#include "../include/armor.h"
#include "../include/human.h"

class Building
{
protected:
	std::vector<std::unique_ptr<Human>> warriors;
public:
	void enter(std::unique_ptr<Human> new_warrior);
	std::unique_ptr<Human> exit();
	void state();

	virtual ~Building() = default;
};

class Barack: public Building
{
public:
	std::vector<std::unique_ptr<Human>> getWarrior(const int& number);
	void createWarriors();
};

class Arena: public Building
{
public:
	std::unique_ptr<Human> fight(std::unique_ptr<Human> human1, std::unique_ptr<Human> human2);
	std::unique_ptr<Human> battle();
};

