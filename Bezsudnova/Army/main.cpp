#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <stdlib.h>
#include <time.h>
#include <vector>

enum Type
{
        Infantry,
        Archer,
        Horseman
};

#include "Units.h"
std::unique_ptr<Unit> createUnit(Type type_)
    {
        switch (type_)
        {
            case Type::Archer:
                return std::unique_ptr<Unit>(new UArcher);
            case Type::Infantry:
                return std::unique_ptr<Unit>(new UInfantry);
            case Type::Horseman:
                return std::unique_ptr<Unit>(new UHorseman);
        }
        return std::unique_ptr<Unit>(new Unit);
    };


#include "Army.h"
template <class typeArmyT>
std::unique_ptr<Army> buildArmy()
{
    typeArmyT builder;
    builder.buildArmy();
    return std::move(builder.army_);
}


int main()
{

    std::unique_ptr<Army> romanArmy = buildArmy<ArmyBuilderRomans>();
    std::unique_ptr<Army> varvarArmy = buildArmy<ArmyBuilderVarvar>();

    std::cout << "Roman Army: \n";
    romanArmy->save(std::cout);

    std::cout << "Varvar Army: \n";
    varvarArmy->save(std::cout);

    //std::cout << "end" ;
    return 0;

}

