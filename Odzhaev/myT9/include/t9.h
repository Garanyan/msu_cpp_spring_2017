/**
 * @brief The class translates words to t9 notation
 */
typedef std::pair<char, std::string> Data; // Тип, хранимый в "map" в данном примере
typedef	std::vector <Data> DATAES;

class T9 final
{
public:
	T9();
	std::string translate(const std::string& str);
private:
	DATAES t_nine;
};


class DataCompare // Класс для функций сравнения
{
public:
	bool operator()(const Data& lhs, const Data& rhs) const
// Функция сравнения для сортировки
	{ return keyLess(lhs.first, rhs.first); }                                      
	bool operator()(const Data& lhs, const Data::first_type& k) const  // Функция сравнения для поиска (форма 1)
	{ return keyLess(lhs.first, k); }
	bool operator()(const Data::first_type& k, const Data& rhs) const // Функция сравнения для поиска (форма 2)
	{ return keyLess(k,rhs.first);	}
private:                            
	bool keyLess(const Data::first_type& k1, const Data::first_type& k2) const// "Настоящая" функция сравнения
	{ return k1 < k2; }
};

