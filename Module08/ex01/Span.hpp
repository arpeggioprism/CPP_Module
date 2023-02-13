#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Span
{
private:
	const unsigned int _n;
	std::vector<int> _v;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &src);
	~Span();
	Span &operator=(const Span &rhs);

	void addNumber(unsigned int n);
	void addNumber(std::vector<int>::iterator begin,
				   std::vector<int>::iterator end);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif
