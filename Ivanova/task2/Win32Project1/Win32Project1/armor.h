#pragma once

class armor {
public:
	int armorType;
	int defence;	// ������
	double	speedPenalty;	// ����� � ��������

	armor(int armorType, int defence, double speedPenalty)	// �����������
		: armorType(armorType), defence(defence), speedPenalty(speedPenalty){}


};
