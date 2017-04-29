#include "../include/Army.h"

#include "stdafx.h"

#include "Human.h"
#include "stdafx.h"

// class Army 
// {
// public:
//     std::vector<Archer> archers_;
//     std::vector<Knight> knights_;
//     std::vector<Peasant> peasants_;
//     void dumpArmy() const;
// };

void Army::dumpArmy() const
{
    std::cout << "LEADER" << std::endl;
    std::cout << leader_->name_ << std::endl;
    std::cout << "ARCHERS" << std::endl;
    for (auto& aa : archers_) {
        std::cout << aa->name_ << std::endl;
    }
    std::cout << "KNIGHTS" << std::endl;
    for (auto& kk : knights_) {
        std::cout << kk->name_ << std::endl;
    }
    std::cout << "PEASANTS" << std::endl;
    for (auto& pp : peasants_) {
        std::cout << pp->name_ << std::endl;
    }
}

ArmyBuilder::~ArmyBuilder()
{
    
}

std::unique_ptr<Army> ArmyBuilder::getArmy()
{
    return std::move(army_);
}

void RomanArmyBuilder::buildArmy()
{
    army_ = std::unique_ptr<Army>(new Army());
}

void RomanArmyBuilder::buildArcher()
{
    army_->archers_.push_back(std::move(std::unique_ptr<Archer>(new RomanArcher())));
}

void RomanArmyBuilder::buildPeasant()
{
}

void RomanArmyBuilder::buildKnight()
{
    army_->knights_.push_back(std::move(std::unique_ptr<Knight>(new RomanKnight())));
}

void RomanArmyBuilder::buildLeader()
{
    army_->leader_ = std::move(std::unique_ptr<Human>(new RomanArcher()));
}

void BarbarianArmyBuilder::buildArmy()
{
    army_ = std::unique_ptr<Army>(new Army());
}

void BarbarianArmyBuilder::buildArcher()
{
}

void BarbarianArmyBuilder::buildPeasant()
{
    army_->peasants_.push_back(std::move(std::unique_ptr<Peasant>(new BarbarianPeasant())));
}

void BarbarianArmyBuilder::buildKnight()
{
    army_->knights_.push_back(std::move(std::unique_ptr<Knight>(new BarbarianKnight())));
}

void BarbarianArmyBuilder::buildLeader()
{
    army_->leader_ = std::move(std::unique_ptr<Human>(new BarbarianPeasant()));
}


std::unique_ptr<Army> ArmyDirector::createArmy(std::unique_ptr<ArmyBuilder> armyBuilder)
{
    armyBuilder->buildArmy();
    for (int i = 0; i < 100; i++) {
        armyBuilder->buildArcher();
    }
    for (int i = 0; i < 100; i++) {
        armyBuilder->buildKnight();
    }
    for (int i = 0; i < 100; i++) {
        armyBuilder->buildPeasant();
    }
    
    armyBuilder->buildLeader();
    return armyBuilder->getArmy();
}
