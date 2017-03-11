#ifndef armor_protector
#define armor_protector
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
#endif
