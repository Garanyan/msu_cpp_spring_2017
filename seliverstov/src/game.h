

class Person
{
public:
	Person(Weapon*, Armor*);
	virtual void takeWeapon(Weapon*);
	virtual void takeArmor(Armor*);
	virtual void attack(Person&);
	virtual void recvAttack(Person&);
protected:
	Weapon* weapon_;
	Armor* armor_;
	bool dead_;
	int hitPoints_;
	int strength_;
	int stamina_;
	int mvSpeed_;
	int baseWeaponMastery_;
	virtual int getWeaponMastery();//for current weapon
};

class Peasant
	:public Person
{
public:
	Peasant(Weapon*, Armor*);
	void takeWeapon(Weapon*);
	void takeArmor(Armor*);
	void attack(Person&);
	void recvAttack(Person&);
private:
	int getWeaponMastery();
};

class Archer
	:public Person
{
public:
	Archer(Weapon*, Armor*);
	void takeWeapon(Weapon*);
	void takeArmor(Armor*);
	void attack(Person&);
	void recvAttack(Person&);
private:
	int getWeaponMastery();
};

class Knight
	:public Person
{
public:
	Knight(Weapon*, Armor*);
	void takeWeapon(Weapon*);
	void takeArmor(Armor*);
	void attack(Person&);
	void recvAttack(Person&);
private:
	int getWeaponMastery();
};

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



class Armor
{
public:
	double baseProt();
	double speedPenalty();
	double getDefModifier(const Weapon&) = 0;
protected:
	double baseProt_;
	double speedPenalty_;
};

class Mail
	:public Armor
{
public:
	Mail();
	double getDefModifier(const Weapon&);
};

class Plate
	:public Armor
{
public:
	Plate();
	double getDefModifier(const Weapon&);
};

class Skin
	:public Armor
{
public:
	Skin();
	double getDefModifier(const Weapon&);
};
