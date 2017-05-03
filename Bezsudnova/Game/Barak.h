#pragma once

class Barak
{
private:
    std::unordered_map<std::string, std::unique_ptr<Units>> arrayUnits;

public:
    void createUnits();
    std::unique_ptr<Units> goToMain(string name_);
    void gotoBarak(std::unique_ptr<Units> unit_);
};

//functions

void Barak::gotoBarak(std::unique_ptr<Units> unit_)
    {
        unit_ -> lifes = 100;
        arrayUnits.emplace( unit_ -> name_, std::move(unit_ ));
    }


std::unique_ptr<Units> Barak::goToMain(string name_)
    {
        auto it = arrayUnits.find(name_);
        if (it == arrayUnits.end())
           return std::unique_ptr<Units>();

        auto unit = std::move(it->second);
        arrayUnits.erase(it);
        return unit;
    };

void Barak::createUnits()
    {
            cout << "Input name: ";
            std::string name_;
            cin >> name_;
            //
            cout << "Type of unit: 1 - Archer; 2 - Knight; 3 - Peasant: " ;
            int typeUnits_ ;
            cin >> typeUnits_;

            while (typeUnits_  > 4)
            {
                cin >> typeUnits_;
            };
            //
            switch (typeUnits_)
            {
                case 1 :
                    arrayUnits.emplace(name_, std::unique_ptr<Units> (new Archer(name_, UnitType::Archer)));
                case 2 :
                   arrayUnits.emplace(name_, std::unique_ptr<Units> (new Knight(name_, UnitType::Knight)));
                case 3 :
                   arrayUnits.emplace(name_, std::unique_ptr<Units> (new Peasant(name_, UnitType::Peasant)));
            }

    };
