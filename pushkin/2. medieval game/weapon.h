#include <iostream>
using namespace std;

class weapon {
public:
	int weaponType;
	int punch;	// ��������� �����������
	int	speed;	// ��������
	int distance;	// ���������

	weapon(int weaponType1, int punch1, int speed1, int distance1) {	// �����������
		weaponType = weaponType1;
		punch = punch1;
		speed = speed1;
		distance = distance1;
	};
};