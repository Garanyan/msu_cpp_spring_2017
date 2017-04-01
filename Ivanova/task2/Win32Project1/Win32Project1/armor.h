#pragma once

class armor {
public:

	armor(int armorType, int defence, double speedPenalty) 
		: armorType(armorType), defence(defence), speedPenalty(speedPenalty) {}

		int armorType;
		int defence;	// защита
	double	speedPenalty;	// штраф к скорости

};

