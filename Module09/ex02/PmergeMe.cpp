#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

bool printError(const std::string &s)
{
	std::cerr << s << std::endl;
	return 1;
}

PmergeMe::PmergeMe(const int &ac, const char **&av)
{
	for (int i(1); i < ac; ++i)
	{
		if (!av[i][0])
			errorExit("Error");
		for (int j(0); av[i][j]; ++j)
			if (!isdigit(av[i][j]) && av[i][j] != ' ')
				errorExit("Error");

		std::istringstream iss(av[i]);
		while (!iss.eof())
		{
			iss >> _u;
			if (errno == ERANGE)
				errorExit("Error: input is out of range");
			_dq.push_back(_u);
			_lst.push_back(_u);
		}
	}

	std::cout << "Before: ";
	for (std::deque<unsigned long int>::const_iterator it(_dq.begin()); it != _dq.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;


	clock_t start1(clock());
	mergeInsertionSortDeque(_dq);
	clock_t end1(clock());
	double time1((end1 - start1) * (1.0 / 100000));

	clock_t start2(clock());
	mergeInsertionSortList(_lst);
	clock_t end2(clock());
	double time2((end2 - start2) * (1.0 / 100000));


	std::cout << "After: ";
	for (std::deque<unsigned long int>::const_iterator it(_dq.begin()); it != _dq.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;


	std::cout << "Time to process a range of " << _dq.size() << " elements with std::deque<unsigned long int> : " << time1 << " us" << std::endl;
	std::cout << "Time to process a range of " << _lst.size() << " elements with std::list<unsigned long int> : " << time2 << " us" << std::endl;
	if (_dq == std::deque<unsigned long int>(_lst.begin(), _lst.end()))
		std::cout << "The sorted sequences are equal." << std::endl;
	else
		std::cout << "The sorted sequences are not equal." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
: _dq(rhs._dq),_lst(rhs._lst) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_lst = rhs._lst;
		_dq = rhs._dq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::errorExit(const std::string &s)
{
	std::cerr << s << std::endl;
	exit(1);
}

void PmergeMe::merge(const std::list<unsigned long int> &left, const std::list<unsigned long int> &right, std::list<unsigned long int> &lst)
{
	std::list<unsigned long int>::const_iterator iter_left(left.begin());
	std::list<unsigned long int>::const_iterator iter_right(right.begin());
	std::list<unsigned long int>::iterator it(lst.begin());

	while (iter_left != left.end() && iter_right != right.end())
		if (*iter_left < *iter_right)
			*it++ = *iter_left++;
		else
			*it++ = *iter_right++;

	while (iter_left != left.end())
		*it++ = *iter_left++;
	while (iter_right != right.end())
		*it++ = *iter_right++;
}

template <typename iter>
void PmergeMe::insertionSort(iter begin, iter end)
{
	iter tmp;
	iter checker;
	iter first(begin++);
	for (; begin != end; ++begin)
	{
		checker = begin;
		tmp = checker;
		while (checker != first && (*--checker) > *tmp)
		{
			std::swap(*checker, *tmp);
			tmp--;
		}
	}
}

void PmergeMe::mergeInsertionSortList(std::list<unsigned long int> &lst)
{
	if (lst.size() < 21)
	{
		insertionSort(lst.begin(), lst.end());
		return;
	}
	unsigned long int middle(lst.size() / 2);
	std::list<unsigned long int> left;
	std::list<unsigned long int> right;
	unsigned long int i(0);
	for (std::list<unsigned long int>::iterator it(lst.begin()); it != lst.end(); it++)
	{
		if (i < middle)
		{
			left.push_back(*it);
			i++;
		}
		else
			right.push_back(*it);
	}
	mergeInsertionSortList(left);
	mergeInsertionSortList(right);
	merge(left, right, lst);
}


void PmergeMe::mergeInsertionSortDeque(std::deque<unsigned long int> &dq)
{
	if (dq.size() < 21)
	{
		insertionSort(dq.begin(), dq.end());
		return;
	}

	unsigned long int middle(dq.size() / 2);
	std::deque<unsigned long int> left;
	std::deque<unsigned long int> right;
	unsigned long int l(0);
	for (std::deque<unsigned long int>::iterator it(dq.begin()); it != dq.end(); it++)
	{
		if (l < middle)
		{
			left.push_back(*it);
			l++;
		}
		else
			right.push_back(*it);
	}
	mergeInsertionSortDeque(left);
	mergeInsertionSortDeque(right);
	mergeDeque(left, right, dq);
}

void PmergeMe::mergeDeque(const std::deque<unsigned long int> &left, const std::deque<unsigned long int> &right, std::deque<unsigned long int> &dq)
{
	std::deque<unsigned long int>::const_iterator iter_left(left.begin());
	std::deque<unsigned long int>::const_iterator iter_right(right.begin());
	std::deque<unsigned long int>::iterator it(dq.begin());

	while (iter_left != left.end() && iter_right != right.end())
		if (*iter_left < *iter_right)
			*it++ = *iter_left++;
		else
			*it++ = *iter_right++;

	while (iter_left != left.end())
		*it++ = *iter_left++;
	while (iter_right != right.end())
		*it++ = *iter_right++;
}
