#ifndef characters_protector
#define characters_protector
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
#endif
