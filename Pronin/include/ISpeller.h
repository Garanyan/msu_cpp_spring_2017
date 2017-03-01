# include "stdafx.h"

/**
* @brief This templated class determines interface for different tranlators (spellers)
*/
template <typename T> 
class ISpeller
{
public:
	/**
	* @brief Virtual destructor
	*/
	virtual ~ISpeller(){}
	/**
	* @brief Abstract method for trnaslation from one layout to another. Types of input and output must match
	*/
	virtual T spell(T const &) = 0;
};