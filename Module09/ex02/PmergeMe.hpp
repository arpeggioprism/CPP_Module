#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <locale>
#include <string>
#include <sstream>
#include <list>
#include <deque>
#include <cerrno>
#include <ctime>

bool printError(const std::string &s);

class PmergeMe
{
private:
	unsigned long int _u;
	std::deque<unsigned long int> _dq;
	std::list<unsigned long int> _lst;

public:
	PmergeMe();
	PmergeMe(const int &ac, const char **&av);
	PmergeMe(const PmergeMe &rhs);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();

	void errorExit(const std::string &s);
	void merge(const std::list<unsigned long int> &left, const std::list<unsigned long int> &right, std::list<unsigned long int> &lst);

	template <typename iter>
	void insertionSort(iter begin, iter end);
	void mergeInsertionSortList(std::list<unsigned long int> &lst);
	void mergeInsertionSortDeque(std::deque<unsigned long int> &dqe);
	void mergeDqe(const std::deque<unsigned long int> &left, const std::deque<unsigned long int> &right, std::deque<unsigned long int> &dqe);
};

#endif
