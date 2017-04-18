/**
 * @brief  The class describes characters, types of characters,
 * their skills (HP,Strength, Speed, weapon mastery, agility, luck)
 */
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
using Points = int;
class Person
{
    public:
    virtual ~Person();
	Person(const std::string & name, DamageType weapon, ArmorType armor);

    Person(const Person& copied) = delete;
	Person& operator=(const Person& copied) = delete;

	Person(person&& movied) {
		charArmor.reset(movied.charArmor.release());
		charWeapon.reset(movied.charWeapon.release());
		return *this;
	}

	Person& operator=(Person&& movied)
	{
		charArmor.reset(movied.charArmor.release());
		charWeapon.reset(movied.charWeapon.release());
		return *this;
	}

    void attacked(person&);
     void setWeapon(Weapon&& weapon){
		 charWeapon = std::move(weapon);
	 }
	 void setArmor(Armor&& armor){
		 charArmor = std::move(armor);
	 }
    private:
        std::unique_ptr <weapon> charWeapon;
		std::unique_ptr <armor> charArmor;
        std::string name;
		Points healthPoints;
		Points strength;
		Points speed;
		Points agility;
		Points luck;
};

class Knight final: public Person
{
	public:
		Knight(const std::string& name)
};

class Peasant final: public Person
{
public:
    Peasant(const std::string& name)

};
class Sharp final: public Person
{
public:
    Sharp(const std::string& name)
};

#endif // PERSON_H_INCLUDED
