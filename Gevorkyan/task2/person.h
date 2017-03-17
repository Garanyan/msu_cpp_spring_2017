#ifndef PERSON_H
#define PERSON_H
class Weapon;
class Armor;
class Person
{
private:
    int power;
    int speed;
    int endurance;
    int ability;
    std::unique_ptr<Weapon> current_weapon;
    //Weapon *current_weapon;
    std::unique_ptr<Armor> current_armor;
    //Armor *current_armor;
public:


     Person(int power,int speed,int endurance,int ability,std::unique_ptr<Weapon> current_weapon,std::unique_ptr<Armor> current_armor) {}
    ~Person(){}

    Person(const Person& copied)=delete;
    Person& operator=(const Person& copied)=delete;

    Person(Person&& movied)
    {
        current_weapon.reset(movie.current_weapon.release());
        current_armor.reset(movie.current_armor.release());
        return *this;
    }
    Person& operator=(person&&movied)
    {
        current_weapon.reset(movie.current_weapon.release());
        current_armor.reset(movie.current_armor.release());
        return *this;
    }
};

class Villager : public Person
{

};

class Archer : public Person
{

};

class Knight : public Person
{

};
#endif // PERSON_H
