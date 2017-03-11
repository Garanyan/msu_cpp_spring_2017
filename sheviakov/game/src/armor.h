/**
 * @brief The base class for armors
 */
class Weapon;

class Armor
{
public:
    /**
     * @brief Basic constructor for armors
     * @param armorType The std::string type of armor
     * @param speedPenalty The speed penalty value of the character fearing the armor
     */
    Armor(const std::string armorType, int speedPenalty);
    ~Armor();
    /**
     * @brief The value of protection against the weapon
     * @param weapon Pointer to the weapon.
     * @return The int value of the protection score
     */
    int getProtectionValue(Weapon *weapon);
    /**
     * @brief The value of the speed penalty of the weapon
     * @param weapon Pointer to the weapon.
     * @return The int value of the protection score
     */
    int getSpeedPenalty();
protected:
    int speedPenalty;
    std::string armorType;
};
