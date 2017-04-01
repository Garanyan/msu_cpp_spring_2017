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


class sword : public weapon {
public:
	sword() : weapon(0, 5, 7, 90) {}
	virtual ~sword() {}

	sword(const sword& copied) = delete;
	sword& operator = (const sword& copied) = delete;

	sword(sword&& x) = default;
	sword& operator = (sword&& x) = default;

};

class shovel : public weapon {
public:
	shovel() : weapon(1, 7, 10, 45) {}
	virtual ~shovel() {}

	shovel(const shovel& copied) = delete;
	shovel& operator = (const shovel& copied) = delete;

	shovel(shovel&& x) = default;
	shovel& operator = (shovel&& x) = default;

};

class bow : public weapon {
public:
	bow() : weapon(1, 7, 10, 45) {}
	virtual ~bow() {}

	bow(const bow& copied) = delete;
	bow& operator = (const bow& copied) = delete;

	bow(bow&& x) = default;
	bow& operator = (bow&& x) = default;

};

class hammer : public weapon {
public:
	hammer() : weapon(3, 7, 10, 45) {}
	virtual ~hammer() {}

	hammer(const hammer& copied) = delete;
	hammer& operator = (const hammer& copied) = delete;

	hammer(hammer&& x) = default;
	hammer& operator = (hammer&& x) = default;

};

