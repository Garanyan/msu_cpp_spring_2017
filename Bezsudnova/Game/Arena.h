#pragma once



class Arena
{

public:
    void Fight(unique_ptr<Units> person1, unique_ptr<Units> person2, Barak *barak1);
};


void Arena::Fight(unique_ptr<Units> person1, unique_ptr<Units> person2, Barak *barak1)
    {
        int hitPerson1;
        int hitPerson2;
        int defencePerson1;
        int defencePerson2;
        int skillPersonArmor1;
        int skillPersonArmor2;
        int skillPersonWeapon1;
        int skillPersonWeapon2;

        hitPerson1 = person1->weapon_->getPower(person2->armor_->getArmorType());
        hitPerson2 = person2->weapon_->getPower(person1->armor_->getArmorType());
        defencePerson1 = person1->armor_->getDefence(person2->weapon_->getWeaponType());
        defencePerson2 = person2->armor_->getDefence(person1->weapon_->getWeaponType());
        skillPersonArmor1 = person1 ->getSkillArmor();
        skillPersonArmor2 = person2 ->getSkillArmor();
        skillPersonWeapon1 = person1 ->getSkillWeapon();
        skillPersonWeapon2 = person2 ->getSkillWeapon();
        int i = 0;


        while ((person1->lifes >= 0) && (person2->lifes >= 0))
        {
            if (defencePerson1*skillPersonArmor1 - skillPersonWeapon2*hitPerson2 < 0)
            {
                person1->lifes = person1->lifes - skillPersonWeapon2*hitPerson2 + skillPersonArmor1*defencePerson1;
            };

            if (defencePerson2*skillPersonArmor2 - skillPersonWeapon1*hitPerson1 < 0)
            {
                person2->lifes = person2->lifes - skillPersonWeapon1*hitPerson1 + skillPersonArmor2*defencePerson2;
            };
            cout << "Hit" <<  defencePerson1*skillPersonArmor1 - skillPersonWeapon2*hitPerson2   << " Lifes "  << person1->lifes << endl;
            cout << "Hit" <<  defencePerson2*skillPersonArmor2 - skillPersonWeapon1*hitPerson1   << " Lifes "  << person2->lifes << endl;
            cout << "///" << endl;
            i=i+1;
            if (i > 101)
            {
                person1 -> lifes = -1;
                person2 -> lifes = -1;
            };
        };


        //after fight
        if (person1->lifes < 0)
        {
            cout << person1->name_ << " is dead" << endl;
        }
        else
        {
            cout << person1->name_ << " is alive" << endl;
            barak1->gotoBarak(std::move(person1));
        };


        if (person2->lifes < 0)
        {
            cout << person2->name_ << " is dead" << endl;
        }
        else
        {
            cout << person2->name_ << " is alive" << endl;
            barak1->gotoBarak(std::move(person2));
        };
    }
