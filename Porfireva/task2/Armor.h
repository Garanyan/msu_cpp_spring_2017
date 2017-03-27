
class Armor
{
    double penalty;
    public:
        Armor(){};
        virtual ~Armor(){}
        Armor(const Armor& /*copied*/) = delete;
        Armor& operator=(const Armor&) = delete ;
};
struct ChainArmorTraits
{
    template<class DamageType>;
    static constexpr Point protection();

}
struct BluntDamage{};
struct SlashingDamage{};
struct PiercingDamage{};
using Point = double;
using Point =double;
class Hauberk final: public Armor
{
};

class Corslet final:public Armor
{
};
