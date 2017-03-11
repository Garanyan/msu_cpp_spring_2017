
/**
 * @brief The base class for weapons
 */
class Weapon 
{
public:
    /**
     * @brief The basic constructor for weapons 
     * @param weaponType The std::string type of weapon
     * @param damageScore The int value of damage scores
     * @param hitDistance The int value of effective damage distance
     * @param speedPenalty The int value of the speed penalty for character of the weapon
     */
    Weapon(const std::string weaponType, int damageScore,
           int hitDistance, int speedPenalty);
    ~Weapon();
    
    /**
     * @brief Get value of speed penalty for the weapon
     * @return The int value of the speed penalty
     */
    int getSpeedPenalty();
    
    /**
     * @brief Get value of effective damage distance for the weapon
     * @return The int value of the damage distance for the weapon
     */
    int getHitDistance();
    
    /**
     * @brief Get damage score
     * @return The int value of the damage score of the weapon
     */
    int getDamageScore();
    
    /**
     * @brief Get the type of the weapon
     * @return The string value of weapon type
     */
    std::string getWeaponType();
protected:
    int speedPenalty;
    int hitDistance;
    int damageScore;
    std::string weaponType;
};
