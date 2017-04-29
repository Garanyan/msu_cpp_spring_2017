#include "Human.h"
#include "stdafx.h"

class Army 
{
public:
    std::vector<std::unique_ptr<Archer>> archers_;
    std::vector<std::unique_ptr<Knight>> knights_;
    std::vector<std::unique_ptr<Peasant>> peasants_;
    std::unique_ptr<Human> leader_;
    void dumpArmy() const;
};


class ArmyBuilder
{
protected:
    std::unique_ptr<Army> army_;
public:
    virtual void buildArmy() = 0;
    virtual void buildKnight() = 0;
    virtual void buildArcher() = 0;
    virtual void buildPeasant() = 0;
    virtual void buildLeader() = 0;
    std::unique_ptr<Army> getArmy();
    virtual ~ArmyBuilder();
};


class RomanArmyBuilder : public ArmyBuilder
{
public:
    void buildArmy() override;
    void buildKnight() override;
    void buildArcher() override;
    void buildPeasant() override;
    void buildLeader() override;
};

class BarbarianArmyBuilder : public ArmyBuilder
{
public:
    void buildArmy() override;
    void buildKnight() override;
    void buildArcher() override;
    void buildPeasant() override;
    void buildLeader() override;
};


class ArmyDirector 
{
public:
    std::unique_ptr<Army> createArmy(std::unique_ptr<ArmyBuilder> armyBuilder);
};
