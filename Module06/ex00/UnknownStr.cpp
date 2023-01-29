#include "UnknownStr.hpp"


UnknownStr::UnknownStr() : _str(NULL), _dvalue(0.0) {}

UnknownStr::UnknownStr(const std::string &s) : _str(s), _dvalue(std::atof(_str.c_str()))
{
	isValid();
}
UnknownStr::UnknownStr(const UnknownStr &src) : _str(src._str), _dvalue(src._dvalue)
{
	*this = src;
}

bool UnknownStr::isUndecided() const
{
	return _str == "nan" || _str == "nanf" || _str == "+inf" || _str == "inf" || _str == "-inf" || _str == "+inff" || _str == "inff" || _str == "-inff";
}

std::string UnknownStr::getStr()
{
	return _str;
}

void UnknownStr::isValid() const
{
	if (isUndecided())
		return;
	int dot = 0;
	if (_str.size() == 0)
		throw InvalidStrException();
	for (u_long i = 0; i < _str.length(); i++)
	{
		if (i == 0 && (_str[i] == '-' || _str[i] == '+'))
			continue;
		if (i + 1 == _str.length())
		{
			if (_str[i] == '.')
				throw InvalidStrException();
			if (_str[i] == 'f')
				break;
		}
		if (_str[i] == '.')
		{
			if (++dot > 1)
				throw InvalidStrException();
			continue;
		}
		if (!isdigit(_str[i]))
			throw InvalidStrException();
	}
}

void UnknownStr::print() const
{
	toChar();
	toInt();
	toFloat();
	toDouble();
}

UnknownStr::~UnknownStr() {}

const char *UnknownStr::InvalidStrException::what() const throw()
{
	return "Invalid Str Exception";
}

void UnknownStr::toFloat() const
{
	float f = std::strtof(_str.c_str(), NULL);
	std::cout << "float: " << f << (f == static_cast<int>(f) ? ".0f" : "f") << std::endl;
}

void UnknownStr::toInt() const
{
	if (isUndecided())
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	if (_dvalue < 0 || 126 < _dvalue)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	int i = std::atoi(_str.c_str());
	std::cout << "int: " << i << std::endl;
}

void UnknownStr::toDouble() const
{
	double d = std::strtod(_str.c_str(), NULL);
	std::cout << "double: " << d << (d - static_cast<int>(d) == 0 ? ".0" : "") << std::endl;
}

void UnknownStr::toChar() const
{
	if (isUndecided())
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if (_dvalue < 0 || 126 < _dvalue)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	char c = static_cast<char>(std::atoi(_str.c_str()));
	std::cout << "char: ";
	if (c >= 32 && c < 127)
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

UnknownStr &UnknownStr::operator=(const UnknownStr &rhs)
{
	if (this != &rhs)
	{
		this->_str = rhs._str;
		this->_dvalue = rhs._dvalue;
	}
	return *this;
}
