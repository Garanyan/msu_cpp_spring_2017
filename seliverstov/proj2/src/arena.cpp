#include "arena.h"

void Arena::enter(Person&& contestant)
{
	people.insert({contestant.nickname(), std::move(contestant)});
}

Person&& Arena::leave(const std::string& nickname)
{
	return std::move(people.at(nickname));
}
