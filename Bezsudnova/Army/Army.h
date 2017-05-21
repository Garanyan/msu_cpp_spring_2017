#pragma once


struct Army
{
    std::vector<std::unique_ptr<Unit>> infantry_;
    std::vector<std::unique_ptr<Unit>> archer_;
    std::vector<std::unique_ptr<Unit>> horseman_;


    void save(std::ostream& out) const
	{
        out << "Infantry - " << infantry_.size() << '\n';
        out << "Archer - " << archer_.size() << '\n';
        out << "Horseman - "<< horseman_.size() << '\n';
	}

};




struct ArmyBuilder
{
     ArmyBuilder()
        : army_(new Army())
    {
    }
    std::unique_ptr<Army> army_;

    virtual void buildArmy() {}

};

struct ArmyBuilderRomans: public ArmyBuilder
{

    void buildArmy()
    {
        srand(time(0));
        int number =  rand() % 20;
        for ( int i = 0; i < number; i++ )
        {
            army_->infantry_.push_back(createUnit(Type::Infantry));
        }
        number =  rand() % 20;
        for ( int i = 0; i < number; i++ )
        {
            army_->archer_.push_back(createUnit(Type::Archer));
        }
        number =  rand() % 20;
        for ( int i = 0; i < number; i++ )
        {
            army_->horseman_.push_back(createUnit(Type::Horseman));
        }
    }
};


struct ArmyBuilderVarvar: public ArmyBuilder
{
    void buildArmy()
    {
        srand(time(0));
        int number =  rand() % 20;
        for (int i = 0; i < number; i++ )
        {
            army_->infantry_.push_back(createUnit(Type::Infantry));
        }
        number =  rand() % 20;
        for (int i = 0; i < number; i++ )
        {
            army_->archer_.push_back(createUnit(Type::Archer));
        }

    }
};
