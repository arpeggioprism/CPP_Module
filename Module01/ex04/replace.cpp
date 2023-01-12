#include "replace.hpp"

void	replace(size_t &pos, std::string &line, const std::string &s1, const std::string &s2)
{
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
}