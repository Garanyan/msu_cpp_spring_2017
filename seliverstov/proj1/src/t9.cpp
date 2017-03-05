#include "../include/t9.h"
#include <stdexcept>

std::string T9::spell(std::string data)
{
	std::string result;
	int lastNumber = -1;
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] == ' ')
		{
			if (lastNumber == 0)
				result.push_back(' ');
			lastNumber = 0;
			result.push_back('0');
		} else if (data[i] >= 'a' && data[i] <= 'z')
		{
			int number, quantity;
			if (data[i] < 'p')
			{
				number = static_cast<int> ((data[i] - 'a') / 3 + 2);
				quantity = static_cast<int> ((data[i] - 'a') % 3 + 1);
			} else
			if (data[i] < 't')
			{
				number = 7;
				quantity = static_cast<int> (data[i] - 'p' + 1);
			} else
			if (data[i] < 'w')
			{
				number = 8;
				quantity = static_cast<int> (data[i] - 't' + 1);
			} else
			{
				number = 9;
				quantity = static_cast<int> (data[i] - 'w' + 1);
			}
			if (lastNumber == number)
				result.push_back(' ');
			lastNumber = number;
			for (int j = 0; j < quantity; j++)
				result.push_back((char) number + '0');
		} else
		{
			throw std::invalid_argument("Wrong T9 usage: only small case "
										"letters and space "
						 				"symbols are accepted\n");
		}
		i++;
	}
	if (result.empty())
		throw std::invalid_argument("Wrong T9 usage: empty string");
	return result;
}
