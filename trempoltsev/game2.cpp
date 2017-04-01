#include <cassert>
#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>

using Points = double;

enum class DamageType
{
    Blunt,
    Slashing,
    Piercing
};

enum class ArmorType
{
    Unarmored,
    Chains,
    Plates
};

struct Armor
{
    virtual ~Armor() = 0;
    
    virtual Points getProtection(DamageType damage) const = 0;
    virtual ArmorType getType() const = 0;
};

Armor::~Armor()
{
}

struct ChainArmor
    : public Armor
{
public:
    Points getProtection(DamageType damage) const override
    {
        switch (damage)
        {
            case DamageType::Blunt: return 10;
            case DamageType::Slashing: return 30;
            case DamageType::Piercing: return 20;
        }
        assert(!"Invalid damage type");
        return 0;
    }
    
    ArmorType getType() const override
    {
        return ArmorType::Chains;
    }
};

struct WithoutArmor
    : public Armor
{
public:
    Points getProtection(DamageType damage) const override
    {
        switch (damage)
        {
            case DamageType::Blunt: return 0;
            case DamageType::Slashing: return 0;
            case DamageType::Piercing: return 0;
        }
        assert(!"Invalid damage type");
        return 0;
    }
    
    ArmorType getType() const override
    {
        return ArmorType::Unarmored;
    }
};

enum class WeaponType
{
    Martial,
    Swords
};

struct Weapon
{
    virtual ~Weapon() = 0;
    
    virtual DamageType getDamageType() const = 0;
    virtual Points getDamage() const = 0;
    virtual WeaponType getType() const = 0;
};

Weapon::~Weapon()
{
}

struct Sword
    : public Weapon
{
    DamageType getDamageType() const override
    {
        return DamageType::Slashing;
    }
    
    Points getDamage() const override
    {
        return 50;
    }
    
    WeaponType getType() const override
    {
        return WeaponType::Swords;
    }
};

struct Fists
    : public Weapon
{
    DamageType getDamageType() const override
    {
        return DamageType::Blunt;
    }
    
    Points getDamage() const override
    {
        return 5;
    }
    
    WeaponType getType() const override
    {
        return WeaponType::Martial;
    }
};

struct Unit
{
    explicit Unit(const std::string& name, Points health)
        : name_(name)
        , armor_(new WithoutArmor())
        , weapon_(new Fists())
        , health_(health)
    {
    }
    
    virtual ~Unit() = 0;
    
    void wearArmor(std::unique_ptr<Armor>&& armor)
    {
        if (armor)
            armor_.reset(armor.release());
        else
            armor_.reset(new WithoutArmor());
    }
    
    void takeWeapon(std::unique_ptr<Weapon>&& weapon)
    {
        if (weapon)
            weapon_.reset(weapon.release());
        else
            weapon_.reset(new Fists());
    }
    
    virtual Points getArmorSkill(ArmorType type) const = 0;
    virtual Points getWeaponSkill(WeaponType type) const = 0;
    
    void attack(Unit& other)
    {
        const auto armorSkill = other.getArmorSkill(other.armor_->getType());
        const auto protection = other.armor_->getProtection(weapon_->getDamageType());
        const auto finalProtection = armorSkill * protection;
        
        const auto weaponSkill = getWeaponSkill(weapon_->getType());
        const auto damage = weapon_->getDamage();
        const auto finalDamage = weaponSkill * damage;
        
        const auto points = finalProtection - finalDamage;
        if (points < 0)
            other.health_ += points;
    }
    
    const std::string& getName() const
    {
        return name_;
    }
    
    Points getHealth() const
    {
        return health_;
    }
    
private:
    const std::string name_;
    std::unique_ptr<Armor> armor_;
    std::unique_ptr<Weapon> weapon_;
    Points health_;
};

Unit::~Unit()
{
}

struct Peasant
    : public Unit
{
    explicit Peasant(const std::string& name)
        : Unit(name, 100)
    {
    }
    
    Points getArmorSkill(ArmorType type) const override
    {
        switch (type)
        {
            case ArmorType::Unarmored: return 1;
            case ArmorType::Chains: return 1;
            case ArmorType::Plates: return 1;
        }
        assert(!"Invalid armor type");
        return 0;
    }
    
    Points getWeaponSkill(WeaponType type) const override
    {
        switch (type)
        {
            case WeaponType::Martial: return 1;
            case WeaponType::Swords: return 1;
        }
        assert(!"Invalid weapon type");
        return 0;
    }
};

struct Monk
    : public Unit
{
    explicit Monk(const std::string& name)
        : Unit(name, 500)
    {
    }
    
    Points getArmorSkill(ArmorType type) const override
    {
        switch (type)
        {
            case ArmorType::Unarmored: return 4;
            case ArmorType::Chains: return 1;
            case ArmorType::Plates: return 1;
        }
        assert(!"Invalid armor type");
        return 0;
    }
    
    Points getWeaponSkill(WeaponType type) const override
    {
        switch (type)
        {
            case WeaponType::Martial: return 6;
            case WeaponType::Swords: return 1;
        }
        assert(!"Invalid weapon type");
        return 0;
    }
};

struct Knight
    : public Unit
{
    explicit Knight(const std::string& name)
        : Unit(name, 250)
    {
    }
    
    Points getArmorSkill(ArmorType type) const override
    {
        switch (type)
        {
            case ArmorType::Unarmored: return 1;
            case ArmorType::Chains: return 2;
            case ArmorType::Plates: return 3;
        }
        assert(!"Invalid armor type");
        return 0;
    }
    
    Points getWeaponSkill(WeaponType type) const override
    {
        switch (type)
        {
            case WeaponType::Martial: return 1;
            case WeaponType::Swords: return 3;
        }
        assert(!"Invalid weapon type");
        return 0;
    }
};

struct Building
{
    virtual ~Building() = 0;
};

Building::~Building()
{
}

struct Arsenal
    : public Building
{
    Arsenal()
    {
        armors_.push_back(make<ChainArmor>());
        armors_.push_back(make<ChainArmor>());

        weapons_.push_back(make<Sword>());
        weapons_.push_back(make<Sword>());
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
        createUnit<Peasant>("John");
        createUnit<Knight>("Tom");
    }
    
    std::unique_ptr<Unit> callUnit(const std::string& name)
    {
        auto it = units_.find(name);
        if (it == units_.end())
            return std::unique_ptr<Unit>();

        auto unit = std::move(it->second);
        units_.erase(it);
        return unit;
    }
    
private:
    template <class T>
    void createUnit(const std::string& name)
    {
        units_.emplace(name, std::unique_ptr<T>(new T(name)));
    }
    
    std::unordered_map<std::string, std::unique_ptr<Unit>> units_;
};

struct Arena
    : public Building
{
    explicit Arena(std::weak_ptr<Arsenal> arsenal)
        : arsenal_(arsenal)
    {
    }
    
    std::unique_ptr<Unit> fight(std::unique_ptr<Unit>&& first, std::unique_ptr<Unit>&& second)
    {
        auto arsenal = arsenal_.lock();
        if (arsenal)
        {
            first->wearArmor(std::move(arsenal->getArmor()));
            first->takeWeapon(std::move(arsenal->getWeapon()));

            second->wearArmor(std::move(arsenal->getArmor()));
            second->takeWeapon(std::move(arsenal->getWeapon()));
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
    void attack(Unit& first, Unit& second)
    {
        first.attack(second);
        std::cout << first.getName() << " attacked " << second.getName() << '\n';
        std::cout << second.getName() << " health = " << second.getHealth() << '\n';
    }
    
    std::weak_ptr<Arsenal> arsenal_;
};

int main()
{
    auto arsenal = std::make_shared<Arsenal>();

    Barack barack;

    Arena arena(arsenal);

    auto john = barack.callUnit("John");
    auto sirTom = barack.callUnit("Tom");
    
    auto lastManStanding = arena.fight(std::move(john), std::move(sirTom));

    if (lastManStanding)
        std::cout << "Winner: " << lastManStanding->getName() << '\n';
    else
        std::cout << "Draw\n";

    return 0;
}
