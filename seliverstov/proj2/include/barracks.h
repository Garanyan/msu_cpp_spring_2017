#ifndef barracks_protector
#define barracks_protector
#include "characters.h"
class Barracks
{
public:
	Person&& leave(std::string);
	void enter(Person&&);
private:
	std::unordered_map <std::string,Person&> people;
};
#endif
