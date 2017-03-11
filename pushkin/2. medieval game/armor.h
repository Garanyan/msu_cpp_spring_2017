#include <iostream>
using namespace std;

class armor {
public:
	int armorType;
	int defence;	// защита
	double	speedPenalty;	// штраф к скорости

	armor(int armorType1, int defence1, double speedPenalty1) {	// конструктор
		armorType = armorType1;
		defence = defence1;
		speedPenalty = speedPenalty1;
	};
};