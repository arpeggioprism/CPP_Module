#include <iostream>
#include <string>

class UnknownStr
{
private:
	std::string _str;
	double _dvalue;
	void toFloat() const;
	void toInt() const;
	void toChar() const;
	void toDouble() const;
	void isValid() const;
	bool isUndecided() const;

public:
	UnknownStr();
	UnknownStr(const std::string &s);
	UnknownStr(const UnknownStr &src);
	~UnknownStr();

	UnknownStr &operator=(const UnknownStr &rhs);

	std::string getType();
	std::string getStr();
	void print() const;
	class InvalidStrException
	{
	public:
		const char *what() const throw();
	};
};
