#include "arsenal.h"

void Arsenal::enter(Person&& person)
{
	people.insert({person.nickname(),std::move(person)});
}

Person&& Arsenal::leave(std::string nickname)
{
	return std::move(people.at(nickname));
}

