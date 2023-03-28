#include "PmergeMe.hpp"

int main(const int ac, const char **av)
{
	if (ac == 1)
		return printError("Error: bad arguments");

	PmergeMe pMergeMe(ac, av);
	return 0;
}
