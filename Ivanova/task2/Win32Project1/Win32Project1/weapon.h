#pragma once

class weapon {
public:
	int weaponType;
	int punch;	// пробивная способность
	int	speed;	// скорость
	int distance;	// дальность

	weapon(int weaponType, int punch, int speed, int distance) 
		: weaponType(weaponType), punch(punch), speed(speed), distance(distance) {}

};



class spade : public weapon {
public:
	spade(int weaponType = 0, int punch = 50, int speed = 80, int distance = 80) :weapon(weaponType, punch, speed, distance) {};
};

class sword : public weapon {
public:
	sword(int weaponType = 1, int punch = 50, int speed = 80, int distance = 80) :weapon(weaponType, punch, speed, distance) {};
};

class bow : public weapon {
public:
	bow(int weaponType = 2, int punch = 50, int speed = 80, int distance = 80) :weapon(weaponType, punch, speed, distance) {};
};

class hammer : public weapon {
public:
	hammer(int weaponType1 = 3, int punch1 = 50, int speed1 = 80, int distance1 = 80) :weapon(weaponType1, punch1, speed1, distance1) {};
};