#include "stdafx.h"

#include "t9.h"


T9::T9()
{
	t_nine.push_back(Data(' ',"0"));
	t_nine.push_back(Data('a',"2"));
	t_nine.push_back(Data('b',"22"));
	t_nine.push_back(Data('c',"222"));
	t_nine.push_back(Data('d',"3"));
	t_nine.push_back(Data('e',"33"));
	t_nine.push_back(Data('f',"333"));
	t_nine.push_back(Data('g',"4"));
	t_nine.push_back(Data('h',"44"));
	t_nine.push_back(Data('i',"444"));
	t_nine.push_back(Data('j',"5"));
	t_nine.push_back(Data('k',"55"));
	t_nine.push_back(Data('l',"555"));
	t_nine.push_back(Data('m',"6"));
	t_nine.push_back(Data('n',"66"));
	t_nine.push_back(Data('o',"666"));
	t_nine.push_back(Data('p',"7"));
	t_nine.push_back(Data('q',"77"));
	t_nine.push_back(Data('r',"777"));
	t_nine.push_back(Data('s',"7777"));
	t_nine.push_back(Data('t',"8"));
	t_nine.push_back(Data('u',"88"));
	t_nine.push_back(Data('v',"888"));
	t_nine.push_back(Data('w',"9"));
	t_nine.push_back(Data('x',"99"));
	t_nine.push_back(Data('y',"999"));
	t_nine.push_back(Data('z',"9999"));
}

std::string T9::translate(const std::string& str)
{
	
	if (str.empty()) {
	        throw std::invalid_argument("String is empty");
	}
/*	sort(t_nine.begin(),t_nine.end(),DataCompare());
	for(DATAES::iterator i=t_nine.begin();i!=t_nine.end();++i)
	{std::cout<<(*i).first<<" "<<(*i).second<<std::endl;
}
*/
	std::string res="";
	std::string tmp="",curr="";
	for (char symbol : str) 
	{
		std::pair<DATAES::iterator, DATAES::iterator> range = equal_range(t_nine.begin(),t_nine.end(), symbol, DataCompare());	
		if(range.first!=range.second) {
			curr=(*range.first).second;
			if (tmp[0] == curr[0]) {
            			res += " ";
			}
		} else { 
			res = symbol + std::string(" is not symbol a-z or space"); 
			throw std::invalid_argument(res);
		}
		tmp=curr;
        	res += curr;
    	}

	return res;
}
