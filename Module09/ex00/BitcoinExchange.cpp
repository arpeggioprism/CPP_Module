#include "BitcoinExchange.hpp"

bool printError(const std::string &s)
{
	std::cerr << s << std::endl;
	return 1;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
	: _db(rhs._db), _line(rhs._line), _date(rhs._date), _value(rhs._value), _key(rhs._key) {}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		_db = rhs._db;
		_line = rhs._line;
		_date = rhs._date;
		_value = rhs._value;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(std::ifstream &file, std::ifstream &database_file)
{
	std::map<Date, float>	_db;
	std::string				_line;
	std::string				_date;
	std::string				_value;
	Date					_key;

	while (getline(database_file, _line))
	{
		if (_line.empty())
			continue ;

		_date = _line.substr(0, _line.find(','));
	 	_key = Date(_date);

		if (_key.is_valid() == false)
			continue ;

		_value = _line.substr(_line.find(',') + 1);
		if (_value.find_first_not_of("0123456789.", 0) != std::string::npos)
			continue ;

		_db[_key] = std::atof(_value.c_str());
	}

	size_t	len;
	// Read file _line by _line and print the _value of the bitcoin at the _date of the transaction.
	while (getline(file, _line))
	{
		if (_line.empty())
			continue ;

		_date = _line.substr(0, _line.find(' '));
		_key	= Date(_date);

		_value = _line.substr(_line.find('|') + 1);
		len = _value.find_first_not_of(" \n\t\v\f\r");
		_value.erase(0, len);
		len = _value.find_last_not_of(" \n\t\v\f\r");
		_value.erase(len + 1);
		if (_value.find(",") != std::string::npos)
			_value.replace(_value.find(","), 1, ".");

		if (_key.is_valid() == false)
			std::cout << "Error: bad input => " << _key.getRaw() << std::endl;
		else if (_value.find_first_not_of("0123456789-.", 0) != std::string::npos)
			std::cout << "Error: bad _value input => " << _value << std::endl;
		else if (_value.size() > 10 || (_value.size() == 10 && _value.compare(STR_INT_MAX) > 0))
			std::cout << "Error: too large a number." << std::endl;
		else if (std::atof(_value.c_str()) < 0.0)
			std::cout << "Error: not a positive number." << std::endl;
		else
		{
			std::map<Date, float>::iterator	it;
			it = _db.lower_bound(_key);
			if (it == _db.begin() && it->first != _key)
				std::cout << "Error: no data that early." << std::endl;
			else if (it == _db.end())
				std::cout << "Error: no data that late." << std::endl;
			else
			{
				if (it->first != _key)
					--it;
				std::cout << _key.getRaw() << " => " << _value << " = " << std::atof(_value.c_str()) * it->second << std::endl;
			}
		}
	}
}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Date::Date() : _raw(), _year(INT_MAX), _month(INT_MAX), _day(INT_MAX), _validity(false)
{}

Date::Date(std::string &str_date)
{
	size_t	len;

	len = str_date.find_first_not_of(" \n\t\v\f\r");
	str_date.erase(0, len);
	len = str_date.find_last_not_of(" \n\t\v\f\r");
	str_date.erase(len + 1);

	_raw = str_date;

	std::string	year, month, day;
	if (str_date.size() != 10)
	{
		_validity = false;
		this->_year = INT_MAX;
		this->_month = INT_MAX;
		this->_day = INT_MAX;
		return ;
	}

	year = str_date.substr(0, 4);
	month = str_date.substr(6, 2);
	day = str_date.substr(8, 2);

	this->_year = std::atoi(year.c_str());
	this->_month = std::atoi(month.c_str());
	this->_day = std::atoi(day.c_str());

	if (_raw[4] == '-' && _raw[7] == '-' && _raw.find_first_not_of("0123456789-") == std::string::npos
		&& (_month > 0 && _month < 13) && (_day > 0 && _day < 32))
	{
		_validity = true;
	}
	else
		_validity = false;
}

Date::Date( const Date & src ) : _raw(src._raw), _year(src._year), _month(src._month), _day(src._day), _validity(src._validity)
{}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Date::~Date()
{}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Date	&Date::operator=(Date const &rhs)
{
	if ( this != &rhs )
	{
		this->_raw = rhs._raw;
		this->_year = rhs._year;
		this->_month = rhs._month;
		this->_day= rhs._day;
		this->_validity = rhs._validity;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool		Date::operator<( Date const & rhs ) const
{
	if (this->_validity == false || rhs.is_valid() == false)
		return (false);

	if (this->_raw.compare(rhs._raw) < 0)
		return true;
	return false;
}

bool		Date::operator>( Date const & rhs ) const
{
	if (this->_validity == false || rhs.is_valid() == false)
		return (false);
	
	if (this->_raw.compare(rhs._raw) > 0)
		return true;
	return false;
}

bool		Date::operator==( Date const & rhs ) const
{
	if (this->_validity == false || rhs.is_valid() == false)
		return (false);

	if (this->_raw.compare(rhs._raw) == 0)
		return true;
	return false;
}

bool		Date::operator<=( Date const & rhs ) const
{
	if (this->_validity == false || rhs.is_valid() == false)
		return (false);

	if (*this < rhs || *this == rhs)
		return true;
	return false;
}

bool		Date::operator>=( Date const & rhs ) const
{
	if (this->_validity == false || rhs.is_valid() == false)
		return (false);

	if (*this > rhs || *this == rhs)
		return true;
	return false;
}

bool		Date::operator!=( Date const & rhs ) const
{
	if (this->_validity == false || rhs.is_valid() == false)
		return (false);

	if (*this == rhs)
		return false;
	return true;
}


bool		Date::is_valid( void ) const
{
	return (this->_validity);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Date::getRaw( void ) const
{
	return _raw;
}


/* ************************************************************************** */
