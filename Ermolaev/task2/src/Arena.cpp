#include "Arena.h"

// Arena
Arena::Arena()
{
    fighters_ = new std::vector<std::unique_ptr<Person>>();
    winners_ = new std::vector<std::unique_ptr<Person>>();
}
std::unique_ptr<Person> Arena::fight(std::unique_ptr<Person>&& first, std::unique_ptr<Person>&& second)
{
    if(showInfo)
        std::cout << "fight:" << std::endl;

    while (true)
    {
        if(showInfo)
        {
            std::cout << "attack: before" << std::endl;
            first->printStats();
            second->printStats();
        }

        first->attack(*second);

        if(showInfo)
        {
            std::cout << "attack: first attacked second" << std::endl;
            first->printStats();
            second->printStats();
        }

        if (second->getHealth() <= 0)
            return std::move(first);

        second->attack(*first);

        if(showInfo)
        {
            std::cout << "attack: second attacked first" << std::endl;
            first->printStats();
            second->printStats();
        }

        if (first->getHealth() <= 0)
            return std::move(second);
    }
}
void Arena::addToFighters(std::unique_ptr<Person>&& person)
{
    fighters_->push_back(std::move(person));
}
std::unique_ptr<Person> Arena::fightsNet()
{
    // as we use olimpic system, the amount of fighters is a power of 2
    assert(isPowerOfTwo(fighters_->size()));

    while(true)
    {
        while(!fighters_->empty())
        {
            auto first = std::move(fighters_->back());
            fighters_->pop_back();
            auto second = std::move(fighters_->back());
            fighters_->pop_back();

            auto winner = fight(std::move(first), std::move(second));

            winners_->push_back(std::move(winner));
        }

        if(winners_->size() == 1)
            return std::move(winners_->back());

        auto tmp = winners_;
        winners_ = fighters_;
        fighters_ = tmp;
    }
}
bool Arena::isPowerOfTwo(int x) const
{
    return (x & (x - 1)) == 0;
}
