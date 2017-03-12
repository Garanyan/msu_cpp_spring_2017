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
	const int shovelDmg = 15;
	const int shovelSpd = 45;
	const int shovelRng = 150;

	const int bKnifeDmg = 20;
	const int bKnifeSpd = 90;
	const int bKnifeRng = 70;

	const int daggerDmg = 10;
	const int daggerSpd = 120;
	const int daggerRng = 65;

	const int glaiveDmg = 35;
	const int glaiveSpd = 35;
	const int glaiveRng = 180;
	
	const int bowDmg = 40;
	const int bowSpd = 30;
	const int bowRng = 10000;

	const int xbowDmg = 90;
	const int xbowSpd = 10;
	const int xbowRng = 20000;

	const int hammerDmg = 80;
	const int hammerSpd = 30;
	const int hammerRng = 90;

	const int swordDmg = 35;
	const int swordSpd = 60;
	const int swordRng = 100;

	const int lswordDmg = 70;
	const int lswordSpd = 45;
	const int lswordRng = 150;

	const int fistDmg = 5;
	const int fistSpd = 180;
	const int fistRng = 50;
}

class Weapon
{
public:
	int baseDmg();
	int baseSpd();
	int baseRange();
	int type();
	virtual ~Weapon() = 0;
protected:
	Weapon(const Weapon&) = delete;
	int type_;
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
