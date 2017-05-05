#pragma once


class Arsenal
{
private:
    std::vector<std::unique_ptr<Weapon>> arrayWeapon;
    std::vector<std::unique_ptr<Armor>> arrayArmor;

public:

    void generateWeapon(int numWeapon);
    void generateArmor(int numArmor);

    std::unique_ptr<Weapon> getWeapon();
    std::unique_ptr<Armor> getArmor();

};


// create
void Arsenal::generateWeapon(int numWeapon)
    {
        int i = 0;
        srand(time(0));

        while ( i < numWeapon )
        {
            int create = rand() % 4;
            switch(create)
            {
                case 0:
                    arrayWeapon.push_back(std::unique_ptr<Sword> (new Sword()));
                    break;
                case 1:
                    arrayWeapon.push_back(std::unique_ptr<Hammer> (new Hammer()));
                    break;
                case 2:
                    arrayWeapon.push_back(std::unique_ptr<Bow> (new Bow()));
                    break;
                case 3:
                    arrayWeapon.push_back(std::unique_ptr<Shovel> (new Shovel()));
                    break;
            };
            i++;
        };
    };

void Arsenal::generateArmor(int numArmor)
    {
        int i = 0;
        srand(time(0));
        while ( i < numArmor )
        {
            int create = rand() % 2;
            switch(create)
            {
                case 0:
                    arrayArmor.push_back(std::unique_ptr<Chain>(new Chain()));
                    break;
                case 1:
                    arrayArmor.push_back(std::unique_ptr<Lats> (new Lats()));
                    break;
            };
            i++;
        };
    };


// take
std::unique_ptr<Weapon> Arsenal::getWeapon()
    {
        auto weapon = std::move(arrayWeapon.back());
        arrayWeapon.pop_back();
        return weapon;
    };

std::unique_ptr<Armor> Arsenal::getArmor()
    {
        auto armor = std::move(arrayArmor.back());
        arrayArmor.pop_back();
        return armor;
    };

