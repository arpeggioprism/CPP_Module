#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return printError("Error: could not open file.");

	std::ifstream	file(av[1]);
	if (!file.is_open())
		return printError("Error: could not open file.");

	std::ifstream	database("data.csv");
	if (!database.is_open())
		return printError("Error: could not open csv data.");

	BitcoinExchange btc(file, database);

	return 0;
}
