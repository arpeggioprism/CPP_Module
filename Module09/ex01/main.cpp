#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return printError("Error: Bad arguments");

	RPN rpn(av[1]);
	return 0;
}
