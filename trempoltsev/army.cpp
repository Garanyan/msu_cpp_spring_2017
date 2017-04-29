#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

struct Unit;

using UnitPtr = std::unique_ptr<Unit>;

struct Unit
{
    enum Type
    {
        Infantry,
        Archer,
        Horseman
    };
    
    virtual ~Unit() {}
    
    virtual Type getType() const = 0;
    
    static UnitPtr create(Type type);
};

std::ostream& operator<< (std::ostream& out, Unit::Type type)
{
    switch (type)
    {
        case Unit::Type::Infantry:
            out << "Infantry";
            break;
        case Unit::Type::Archer:
            out << "Archer";
            break;
        case Unit::Type::Horseman:
            out << "Horseman";
            break;
    }
    return out;
}

struct Infantry : public Unit
{
    Type getType() const override
    {
        return Unit::Infantry;
    }
};

struct Archer : public Unit
{
    Type getType() const override
    {
        return Unit::Archer;
    }
};

struct Horseman : public Unit
{
    Type getType() const override
    {
        return Unit::Horseman;
    }
};

UnitPtr Unit::create(Type type)
{
    switch (type)
    {
        case Unit::Infantry:
            return UnitPtr(new ::Infantry());
        case Unit::Archer:
            return UnitPtr(new ::Archer());
        case Unit::Horseman:
            return UnitPtr(new ::Horseman());
    }

    assert(!"invalid unit type");
    return UnitPtr();
}

struct Army
{
    std::vector<UnitPtr> infantry_;
    std::vector<UnitPtr> archers_;
    std::vector<UnitPtr> horsemen_;
    
    void save(std::ostream& out) const
    {
        for (auto& i : infantry_)
            out << i->getType() << '\n';
        for (auto& a : archers_)
            out << a->getType() << '\n';
        for (auto& h : horsemen_)
            out << h->getType() << '\n';
    }
    
    void load(std::istream& in)
    {
        std::string line;
        while (in >> line)
        {
            if (line == "Infantry")
                infantry_.push_back(
                    Unit::create(Unit::Infantry));
            else if (line == "Archer")
                infantry_.push_back(
                    Unit::create(Unit::Archer));
            else if (line == "Horseman")
                infantry_.push_back(
                    Unit::create(Unit::Horseman));
        }
    }
};

using ArmyPtr = std::unique_ptr<Army>;

struct ArmyBuilder
{
    ArmyBuilder()
        : army_(new Army())
    {
    }
    
    virtual void buildInfantry() {}
    virtual void buildArchers() {}
    virtual void buildHorsemen() {}

    ArmyPtr army_;
};

struct RomanArmyBuilder : public ArmyBuilder
{
    void buildInfantry() override
    {
        for (auto i = 0; i < 5; ++i)
            army_->infantry_.push_back(
                Unit::create(Unit::Infantry));
    }

    void buildArchers() override
    {
        for (auto i = 0; i < 2; ++i)
            army_->archers_.push_back(
                Unit::create(Unit::Archer));
    }

    void buildHorsemen() override
    {
        for (auto i = 0; i < 1; ++i)
            army_->horsemen_.push_back(
                Unit::create(Unit::Horseman));
    }
};

struct BarbarianArmyBuilder : public ArmyBuilder
{
    void buildInfantry() override
    {
        for (auto i = 0; i < 7; ++i)
            army_->infantry_.push_back(
                Unit::create(Unit::Infantry));
    }
    
    void buildArchers() override
    {
        for (auto i = 0; i < 3; ++i)
            army_->archers_.push_back(
                Unit::create(Unit::Archer));
    }
};

struct ArmyDirector
{
    template <class ArmyBuilderT>
    static ArmyPtr buildArmy()
    {
        ArmyBuilderT builder;
        builder.buildInfantry();
        builder.buildArchers();
        builder.buildHorsemen();
        return std::move(builder.army_);
    }
};

int main()
{
    auto romans = ArmyDirector::buildArmy<RomanArmyBuilder>();
    //romans->save(std::cout);
    
    auto barbarians =
        ArmyDirector::buildArmy<BarbarianArmyBuilder>();
    
    std::stringstream buf;
    romans->save(buf);
    
    Army army;
    army.load(buf);
    
    army.save(std::cout);

    return 0;
}
