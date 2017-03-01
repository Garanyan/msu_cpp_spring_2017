/**
 * @brief The class translates words to t9 notation
 */
class T9 final
{
public:
    /**
     * @brief Translate a text to t9 notation
     * @param text Text to translate. It contains only a-z and space characters
     * @return The text in T9 notation. It contains only digits and spaces
     * @throw std::invalid_argument If source text is empty
     * @throw std::invalid_argument If source text is contain invalid characters
     */
    std::string spell(const std::string& text);
};
