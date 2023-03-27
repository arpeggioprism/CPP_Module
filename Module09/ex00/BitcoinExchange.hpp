#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <climits>

#define STR_INT_MAX std::string("2147483647")

bool printError(const std::string &s);

class Date
{
public:
	Date(void);
	Date(std::string &str_date);
	Date(Date const &src);
	~Date();

	Date	&operator=(Date const &rhs);
	bool	operator<(Date const &rhs) const;
	bool	operator>(Date const &rhs) const;
	bool	operator==(Date const &rhs) const;
	bool	operator<=(Date const &rhs) const;
	bool	operator>=(Date const &rhs) const;
	bool	operator!=(Date const &rhs) const;
	bool	is_valid( void ) const;

	std::string	getRaw( void ) const;

private:
	std::string	_raw;
	int			_year;
	int			_month;
	int			_day;
	bool		_validity;

};

class BitcoinExchange
{
private:
	std::map<Date, float>	_db;
	std::string				_line;
	std::string				_date;
	std::string				_value;
	Date					_key;
	
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	BitcoinExchange(std::ifstream &file, std::ifstream &database);
	~BitcoinExchange();
};

#endif