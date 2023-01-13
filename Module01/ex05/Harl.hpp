#pragma once
#include <string>
#include <iostream>


class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	void (*fp[4])(void);
	Harl();
	~Harl();
	void set_fp(void (**fp)(void));
	void complain(std::string level);
};

