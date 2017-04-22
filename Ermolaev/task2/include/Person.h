#pragma once

#include "utils.h"
#include "stdafx.h"
#include "Armor.h"
#include "Weapon.h"

// Person
class Person
{
public:
    explicit Person(std::string name, Points health);
    virtual ~Person() = 0;

    Person(const Person& copied) = delete;
    Person& operator= (const Person& copied) = delete;

    virtual std::string getJob() const = 0;
    void printStats();
    virtual Points getDamageTypeSkill(DamageType type) const = 0;
    void attack(Person &enemy);
    void wearArmor(std::unique_ptr<Armor>&& armor);
    void takeWeapon(std::unique_ptr<Weapon>&& weapon);
    const std::string& getName() const;
    Points getHealth() const;
private:
    const std::string name_;
    Points health_;
    std::unique_ptr<Armor> armor_;
    std::unique_ptr<Weapon> weapon_;
};

// Peasant
class Peasant
        :public Person
{
public:
    explicit Peasant(std::string name="None", Points health=50);
    Points getDamageTypeSkill(DamageType type) const override;
    std::string getJob() const override;
};

// Knight
class Knight
        :public Person
{
public:
    explicit Knight(std::string name="None", Points health=100);
    Points getDamageTypeSkill(DamageType type) const override;
    std::string getJob() const override;
};

// Archer
class Archer
        :public Person
{
public:
    explicit Archer(std::string name="None", Points health=80);
    Points getDamageTypeSkill(DamageType type) const override;
    std::string getJob() const override;
};

