#ifndef arsenal_protector
#define arsenal_protector
#include "armor.h"
#include "weapons.h"
#include "person.h"
class Arsenal
{
public:
	Person&& leave(std::string);
	void enter(Person&&);
	Weapon&& giveWeapon(std::string, Weapon&&, int);
	Armor&& giveArmor(std::string, Armor&&, int);
private:
	std::unordered_map <std::string, Person&> people;
	std::stack <Weapon&> weaponStore[WpnType::SIZE];
	std::stack <Armor&> armorStore[ArmorType::SIZE];
};
#endif
