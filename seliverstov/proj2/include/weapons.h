#ifndef weapons_protector
#define weapons_protector
class Weapon
{
public:
	int baseDmg();
	int baseSpd();
	int baseRange();
	virtual ~Weapon() = 0;
protected:
	int baseDmg_;
	int baseSpd_;
	int baseRange_;
};

class Shovel
	:public Weapon
{
public:
	~Shovel();
	Shovel();
};

class Bow
	:public Weapon
{
public:
	~Bow();
	Bow();
};

class Hammer
	:public Weapon
{
public:
	~Hammer();
	Hammer();
};

class Sword
	:public Weapon
{
public:
	~Sword();
	Sword();
};

class Fist
	:public Weapon
{
public:
	~Fist();
	Fist();
};
#endif
