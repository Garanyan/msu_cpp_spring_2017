#include <iostream>
using namespace std;

class armor {
public:
	int armorType;
	int defence;	// ������
	double	speedPenalty;	// ����� � ��������

	armor(int armorType1, int defence1, double speedPenalty1) {	// �����������
		armorType = armorType1;
		defence = defence1;
		speedPenalty = speedPenalty1;
	};
};