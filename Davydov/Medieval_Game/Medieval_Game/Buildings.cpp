#pragma once
#include "..//MCS_MGame2//Units.cpp"

#include <vector>
#include <unordered_map>


struct Building
{
	Building(const Building& copied) = delete;
	Building& operator=(const Building& copied) = delete;
	Building() {};
	virtual ~Building() = 0;
};

//Building::~Building(){}

struct Arsenal
	: public Building
{
	Arsenal()
	{
		armors_.push_back(make<ChainArmor>());
		armors_.push_back(make<ChainArmor>());

		weapons_.push_back(make<Hummer>());
		weapons_.push_back(make<Hummer>());
	}

	std::unique_ptr<Armor> getArmor()
	{
		if (armors_.empty())
			return std::unique_ptr<Armor>();

		auto armor = std::move(armors_.back());
		armors_.pop_back();
		return armor;
	}

	void putArmor(std::unique_ptr<Armor>&& armor)
	{
		armors_.push_back(std::move(armor));
	}

	std::unique_ptr<Weapon> getWeapon()
	{
		if (weapons_.empty())
			return std::unique_ptr<Weapon>();

		auto weapon = std::move(weapons_.back());
		weapons_.pop_back();
		return weapon;
	}

	void putWeapon(std::unique_ptr<Weapon>&& weapon)
	{
		weapons_.push_back(std::move(weapon));
	}

private:
	template <class T>
	std::unique_ptr<T> make()
	{
		return std::unique_ptr<T>(new T());
	}

	std::vector<std::unique_ptr<Armor>> armors_;
	std::vector<std::unique_ptr<Weapon>> weapons_;
};

struct Barack
{
	Barack()
	{
		createNPC<Peasant>("John");
		createNPC<Knight>("Tom");
	}

	std::unique_ptr<NPC> callUnit(const std::string& name)
	{
		auto it = npcs_.find(name);
		if (it == npcs_.end())
			return std::unique_ptr<NPC>();

		auto npc = std::move(it->second);
		npcs_.erase(it);
		return npc;
	}

private:
	template <class T>
	void createNPC(const std::string& name)
	{
		npcs_.emplace(name, std::unique_ptr<T>(new T(std::move(name))));
		std::unique_ptr<T>(new T(""));
		npcs_.emplace(name, nullptr);
	}

	std::unordered_map<std::string, std::unique_ptr<NPC>> npcs_;
};

struct Arena
	: public Building
{
	explicit Arena(std::weak_ptr<Arsenal> arsenal)
		: arsenal_(arsenal)
	{
	}

	std::unique_ptr<NPC> fight(std::unique_ptr<NPC>&& first, std::unique_ptr<NPC>&& second)
	{
		auto arsenal = arsenal_.lock();
		if (arsenal)
		{
			first->eq_armor(std::move(arsenal->getArmor()));
			first->eq_weapon(std::move(arsenal->getWeapon()));

			second->eq_armor(std::move(arsenal->getArmor()));
			second->eq_weapon(std::move(arsenal->getWeapon()));
		}

		while (true)
		{
			attack(*first, *second);
			if (second->getHealth() < 0)
				return std::move(first);

			attack(*second, *first);
			if (first->getHealth() < 0)
				return std::move(second);
		}
	}

private:
	void attack(NPC& first, NPC& second)
	{
		first.attack(second);
		std::cout << first.getName() << " attacked " << second.getName() << '\n';
		std::cout << second.getName() << " health = " << second.getHealth() << '\n';
	}

	std::weak_ptr<Arsenal> arsenal_;
};
