#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "./" << argv[0] << " filename s1 s2" << std::endl;
		return 1;
	}
	std::string		filename(argv[1]);
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::string		line;
	std::ifstream	ifile;
	std::ofstream	ofile(filename + ".replace");
	
	ifile.open(argv[1]);
	if (!ifile.is_open())
	{
		std::cout << "Error: cannot open file. Make sure the filename is correct." << std::endl;
		return 1;
	}
	if (s1.empty())
	{
		std::cout << "Error: cannot replace empty string with s2." << std::endl;
		return 1;
	}

}