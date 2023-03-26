#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <locale>

bool printError(const std::string &s);

class RPN
{
private:
	std::stack<int> _stack;
	int	_tmp;

public:
	RPN();
	RPN(const RPN &rhs);
	RPN &operator=(const RPN &rhs);
	RPN(std::string str);
	~RPN();

	void errorExit(const std::string &s);
};

#endif
