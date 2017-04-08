#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

enum class WeaponType
{
    Sword,
    Hammer

};

enum class ArmorType
{
    Chain,
    Lats
};

enum class  UnitType
{
    Peasant,
    Archer,
    Knight
};

class Armor
{
public:
	virtual ArmorType getArmorType() {};
	virtual int getDefence(WeaponType weapon_) {};
	virtual ~Armor(){}
};

class Chain : public Armor
{
public:
    int defense_;
   	ArmorType getArmorType(void)
	{
	    return ArmorType::Chain;
	}

	int getDefence(WeaponType weapon_)
	{
		switch(weapon_)
		{
		    case WeaponType::Hammer: return 10;
		    case WeaponType::Sword: return 10;
		}
	}
};

class Lats : public Armor
{
public:
   	ArmorType getArmorType(void)
	{
	    return ArmorType::Lats;
	}

	int getDefence(WeaponType weapon_)
	{
		switch(weapon_)
		{
		    case WeaponType::Hammer: return 20;
		    case WeaponType::Sword: return 25;
		}
	}


};



class Weapon
{
public:
	virtual WeaponType getWeaponType() {};
	virtual int getPower(ArmorType armor_) {};
	virtual ~Weapon(){} // деструктор
};

class Sword : public Weapon
{
public:
    int power_;
	WeaponType getWeaponType(void)
	{
	    return WeaponType::Sword;
	}

	int getPower(ArmorType armor_)
	{
		switch(armor_)
		{
		    case ArmorType::Chain: return 20;
		    case ArmorType::Lats : return 15;
		}
	}
};

class Hammer: public Weapon
{
public:
	WeaponType getWeaponType(void)
	{
		return WeaponType::Hammer;
	}

	int getPower(ArmorType armor_)
	{
		switch(armor_)
		{
		    case ArmorType::Chain: return 20;
		    case ArmorType::Lats : return 25;
		}
	}

};


class Units
{
public:
	std::string name_;
	Armor *armor_;
	Weapon *weapon_;
	int lifes;
    UnitType type_;

	Units(string name, int power, UnitType unit_)
	{
		name_ = name;
		lifes = 100;
		type_ = unit_;
	}

	double getSkill ()
	{
	    switch(type_)
	    {
	        case UnitType::Archer : return 2;
	        case UnitType::Knight : return 3;
	        case UnitType::Peasant : return 0;
	    }
	}


	template<class T>
	int setWeapon (T *gift)
	{
		weapon_ = gift;
		return 0;
	}

	template<class T>
	int setArmor (T *gift)
	{
		armor_ = gift;
		return 0;
	}


	WeaponType getWeapon ()
	{
		return weapon_->getWeaponType();
	}

	ArmorType getArmor()
	{
		return armor_->getArmorType();
	}
};


void Fight(Units *person1, Units *person2)
{
    int hitPerson1;
    int hitPerson2;
    int defencePerson1;
    int defencePerson2;
    int skillPerson1;
    int skillPerson2;

    hitPerson1 = person1->weapon_->getPower(person2->armor_->getArmorType());
    hitPerson2 = person2->weapon_->getPower(person1->armor_->getArmorType());
    defencePerson1 = person1->armor_->getDefence(person2->weapon_->getWeaponType());
    defencePerson2 = person2->armor_->getDefence(person1->weapon_->getWeaponType());
    skillPerson1 = person1 ->getSkill();
    skillPerson2 = person2 ->getSkill();

    cout << person1->lifes;
    while ((person1->lifes > 0) && (person2->lifes > 0))
    {
        if (defencePerson1 - skillPerson2*hitPerson2 < 0)
        {
            person1->lifes = person1->lifes - skillPerson2*hitPerson2 + defencePerson1;
        };

        if (defencePerson2 - skillPerson1*hitPerson1 < 0)
        {
            person2->lifes = person2->lifes - skillPerson1*hitPerson1 + defencePerson2;
        };
        cout << "Hit" <<  defencePerson1 - skillPerson2*hitPerson2   << " Lifes "  << person1->lifes << endl;
        cout << "Hit" <<  defencePerson2 - skillPerson1*hitPerson1   << " Lifes "  << person2->lifes << endl;
        cout << "///" << endl;
    };
}


class Arsenal
{
   std::vector<Weapon> myVector;
};

int main()
{
	//
	Units person1("Jon" , 1 , UnitType::Archer );
	Units person2("Reddead", 1 , UnitType::Peasant );

	//
	Sword sword1;
	Hammer hammer1;
    Chain chain1;
    Lats lats1;

	//
	person1.setWeapon( &sword1 );
	person1.setArmor( &chain1 );
	person2.setWeapon( &hammer1 );
	person2.setArmor( &lats1 );

    Fight( &person1, &person2 );

	cout<< "END..." << endl;
}
