#include "replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " fileName s1 s2" << std::endl;
		return 1;
	}
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);

	if (s1.empty())
	{
		std::cout << "Error: cannot replace empty string with s2." << std::endl;
		return 1;
	}
	std::ifstream	ifs;
	
	ifs.open(argv[1]);
	if (!ifs.is_open())
	{
		std::cout << "Error: cannot open file. Make sure the fileName is correct." << std::endl;
		return 1;
	}
	std::string		fileName(argv[1]);
	std::string		line;
	std::ofstream	ofs(fileName + ".replace");
	size_t			pos;

	while (getline(ifs, line, '\0'))
	{
		pos = 0;
		replace(pos, line, s1, s2);
		ofs << line;
	}
	ifs.close();
	ofs.close();
	return 0;
}