#include "stdafx.h"
#include "t9.h"
#include <stdexcept>

std::string T9::spell(std::string text)
{
	std::string result;
	int i = 0;
	int times;
	int num_last=35;
	int num_current=123;
	while (text[i] != '\0')
	{
		
		if (text[i] == ' ') 
		{
			num_current=0;
			if (num_last==num_current) result.push_back(' ');
			result.push_back('0');
		}else if (text[i] == 's') {
			
			num_current=7;
			if (num_last==num_current) result.push_back(' ');
			result.append("7777");
			
		
		}else if (text[i] == 'z') {
			
			num_current=9;
			if (num_last==num_current) result.push_back(' ');
			result.append("9999");
		

		}else if( text[i] < 's' && text[i] >= 'a')
		{
			num_current = int((text[i] - 'a')/3+2);
			if (num_last==num_current) result.push_back(' ');
			times = int((text[i]- 'a' )%3);
			for(int j = 0; j <= times; ++j)
				result.push_back((char) num_current +'0');
			
			

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
