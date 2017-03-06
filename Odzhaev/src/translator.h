class Translator final
{
public:
	std::string translate(const std::string& str);
};

typedef std::pair<char, std::string> Data;
class DataCompare{
public:
	bool operator()(const Data& lhs, const Data& rhs) const
	{ return keyLess(lhs.first, rhs.first); }                                      
	bool operator()(const Data& lhs, const Data::first_type& k) const  
	{ return keyLess(lhs.first, k); }
	bool operator()(const Data::first_type& k, const Data& rhs) const
	{ return keyLess(k,rhs.first);	}
private:                            
	bool keyLess(const Data::first_type& k1, const Data::first_type& k2) const
	{ return k1 < k2; }
};

