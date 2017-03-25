#pragma once

class armor {
public:
	int armorType;
	int defence;	// защита
	double	speedPenalty;	// штраф к скорости

	armor(int armorType, int defence, double speedPenalty)	// конструктор
		: armorType(armorType), defence(defence), speedPenalty(speedPenalty){}


};
