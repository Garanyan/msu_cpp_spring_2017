
/**
 * @brief The base class for characters 
 */
class Weapon;
class Armor;

class Character
{
public:
    /**
     * @brief Construct basic charachter 
     * @param power Power of the character
     * @param health Amount of character's health points
     * @param speed Speed of relocation of the character
     * @param weaponSkill Armament skill of the character
     */
    Character(int power, int health, int speed, int weaponSkill);
    ~Character();

    /**
     * @brief Set the new weapon to the character
     * @param weapon Pointer to the weapon or NULL to drop weapon
     */
    void setWeapon(Weapon *weapon);
    
    /**
     * @brief Get pointer to the character's weapon
     * @return The Weapon class pointer to the character's weapon or NULL if character hasn't weapon 
     */
    Weapon *getWeapon();
    
    /**
     * @brief Set the new armor to the character
     * @param armor Pointer to the new armor of the character or NULL to drop armor
     */
    void setArmor(Armor *armor);
    
    /**
     * @brief Get the pointer to the character's armor 
     * @return The Armor class pointer to the character's armor or NULL if charater hasn't armor
     */
    Armor *getArmor();
    
    /**
     * @brief The method calculates and substracts damage score from health points of character
     * @param adversary The Character class pointer to character that hitted the character
     */
    void calculateDamage(Character *adversary);
    
    /**
     * @brief The method call the calculateDamage mathod of enemy character 
     * @param enemy The Character pointer to the enemy
     */
    void hitEnemy(Character *enemy);
    
protected:
   int power;
   int health;
   int speed;
   int weaponSkill;
   Weapon *weapon;
   Armor *armor;
};
