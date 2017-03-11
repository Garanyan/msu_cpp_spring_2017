#ifndef arena_protector
#define arena_protector
#include "person.h"
class Arena
{
public:
	void enter(Person&&);
	Person&& leave(std::string);
private:
	std::unordered_map <std::string, Person&> people;
};
#endif
