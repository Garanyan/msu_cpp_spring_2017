#include "stdafx.h"
#include "t9.h"
<<<<<<< 39f02bebfc853993d3e9b7417978f7aa5a4f5f0b
#include <stdexcept>
=======

>>>>>>> dbe38d2d3d8f09ac34b0af2920a7d8078097f8ce

std::string T9::spell(std::string text)
{
	std::string result;
	int i = 0;
	int times;
	int num_last=35;
	int num_current=123;
	while (text[i] != '\0')
	{
<<<<<<< 39f02bebfc853993d3e9b7417978f7aa5a4f5f0b
		
		if (text[i] == ' ') 
=======

		if (text[i] == ' ')
>>>>>>> dbe38d2d3d8f09ac34b0af2920a7d8078097f8ce
		{
			num_current=0;
			if (num_last==num_current) result.push_back(' ');
			result.push_back('0');
		}else if (text[i] == 's') {
<<<<<<< 39f02bebfc853993d3e9b7417978f7aa5a4f5f0b
			
			num_current=7;
			if (num_last==num_current) result.push_back(' ');
			result.append("7777");
			
		
		}else if (text[i] == 'z') {
			
			num_current=9;
			if (num_last==num_current) result.push_back(' ');
			result.append("9999");
		
=======

			num_current=7;
			if (num_last==num_current) result.push_back(' ');
			result.append("7777");


		}else if (text[i] == 'z') {

			num_current=9;
			if (num_last==num_current) result.push_back(' ');
			result.append("9999");

>>>>>>> dbe38d2d3d8f09ac34b0af2920a7d8078097f8ce

		}else if( text[i] < 's' && text[i] >= 'a')
		{
			num_current = int((text[i] - 'a')/3+2);
			if (num_last==num_current) result.push_back(' ');
			times = int((text[i]- 'a' )%3);
			for(int j = 0; j <= times; ++j)
				result.push_back((char) num_current +'0');
<<<<<<< 39f02bebfc853993d3e9b7417978f7aa5a4f5f0b
			
			
=======


>>>>>>> dbe38d2d3d8f09ac34b0af2920a7d8078097f8ce

		}
		else if(text[i] <= 'z' && text[i] >= 'a')
		{
			num_current = int((text[i] - 'a'-1)/3+2);
			if (num_last==num_current) result.push_back(' ');
			times = int((text[i]- 'a'-1)%3);
			for(int j = 0; j <= times; ++j)
				result.push_back((char) num_current +'0');
		}
		else throw std::invalid_argument("Wrong symbols\n");
		num_last=num_current;
		i++;
	}
	if (result.empty())
		throw std::invalid_argument("Wrong T9 usage: empty string");
	return result;
}
