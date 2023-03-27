#include "RPN.hpp"

bool printError(const std::string &s)
{
	std::cerr << s << std::endl;
	return 1;
}


RPN::RPN(std::string str)
{
	for (std::string::iterator it(str.begin()); it !=str.end(); ++it)
	{
		if (isdigit(*it))
			_stack.push(*it - 48);
		else if (*it == ' ')
			continue;
		else if (_stack.size() > 1)
			switch (*it)
			{
				case '+':	_tmp = _stack.top();
							_stack.pop();
							_stack.top() += _tmp;
													break;
				case '-':	_tmp = _stack.top();
							_stack.pop();
							_stack.top() -= _tmp;
													break;
				case '*':	_tmp = _stack.top();
							_stack.pop();
							_stack.top() *= _tmp;
													break;
				case '/':	_tmp = _stack.top();
							_stack.pop();
							_stack.top() /= _tmp;
													break;
				default:	errorExit("Error");
			}
		else
			errorExit("Error");
	}

	if (_stack.size() == 1)
	{
		std::cout << _stack.top() << std::endl;
		exit(0);
	}
	else
		errorExit("Error");
}

RPN::RPN() {}

RPN::RPN(const RPN &rhs)
: _stack(rhs._stack),_tmp(rhs._tmp) {}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		_tmp = rhs._tmp;
		_stack = rhs._stack;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::errorExit(const std::string &s)
{
	std::cerr << s << std::endl;
	exit(1);
}
