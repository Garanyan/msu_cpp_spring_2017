/**
 * @brief The class decodes words to t9 notation
 * @author Leonid Tkachenko
 */

#ifndef _T9_SPELLING__
#define __T9_SPELLING__

#include "stdafx.h"

class T9_Spelling final
{
public:
    /**
     * @brief Decode a text to t9 notation
     * @param text Text to decode. It contains only a-z and space characters
     * @return The text in T9 notation. It contains only digits and spaces
     * @throw std::invalid_argument If source text is empty
     * @throw std::invalid_argument If source text is contain invalid characters
     */
    std::string spell(const std::string& text);

/**
     * @brief Get a code for the letter
     * @param ch Letter to decode. It contains only a-z and space characters
     * @return The text in T9 notation. It contains only digits and spaces
     * @throw std::invalid_argument If source text is empty
     * @throw std::invalid_argument If source text is contain invalid characters
     */
	std::string getCodeForLetter(char ch);
};

#endif
