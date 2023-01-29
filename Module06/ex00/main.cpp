#include "UnknownStr.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguements" << std::endl;
		return 1;
	}
	try
	{
		UnknownStr str(argv[1]);
		str.print();
	}
	catch (UnknownStr::InvalidStrException &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}