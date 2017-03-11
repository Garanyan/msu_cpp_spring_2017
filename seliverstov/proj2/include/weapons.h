#ifndef weapons_protector
#define weapons_protector

enum class WpnType
{
	FIST,
	SWORD,
	HAMMER,
	SHOVEL,
	BOW,
	GLAIVE,
	XBOW,
	BKNIFE,
	LSWORD,
	DAGGER
};

namespace WeaponStats
{
	const int ShovelDmg = 15;
	const int ShovelSpd = 45;
	const int ShovelRng = 150;

	const int BKnifeDmg = 20;
	const int BKnifeSpd = 90;
	const int BKnifeRng = 70;

	const int DaggerDmg = 10;
	const int DaggerSpd = 120;
	const int DaggerRng = 65;

	const int GlaiveDmg = 35;
	const int GlaiveSpd = 35;
	const int GlaiveRng = 180;
	
	const int BowDmg = 40;
	const int BowSpd = 30;
	const int BowRng = 10000;

	const int XbowDmg = 90;
	const int XbowSpd = 10;
	const int XbowRng = 20000;

	const int HammerDmg = 80;
	const int HammerSpd = 30;
	const int HammerRng = 90;

	const int SwordDmg = 35;
	const int SwordSpd = 60;
	const int SwordRng = 100;

	const int LswordDmg = 70;
	const int LswordSpd = 45;
	const int LswordRng = 150;

	const int FistDmg = 5;
	const int FistSpd = 180;
	const int FistRng = 50;
}

class Weapon
{
public:
	int baseDmg();
	int baseSpd();
	int baseRange();
	virtual ~Weapon() = 0;
protected:
	Weapon(const Weapon&) = delete;
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

class ButcherKnife
	:public Weapon
{
public:
	~ButcherKnife();
	ButcherKnife();
};

class Dagger
	:public Weapon
{
public:
	~Dagger();
	Dagger();
};

class Glaive
	:public Weapon
{
public:
	~Glaive();
	Glaive();
};

class Bow
	:public Weapon
{
public:
	~Bow();
	Bow();
};

class Crossbow
	:public Weapon
{
public:
	~Crossbow();
	Crossbow();
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

class Longsword
	:public Weapon
{
public:
	~Longsword();
	Longsword();
};

class Fist
	:public Weapon
{
public:
	~Fist();
	Fist();
};

#endif
