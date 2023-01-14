#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
	std::cout << "[DEBUG]\n"
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::error()
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::info()
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::complain(std::string level)
{
	static void (Harl::*fp[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	bool		flag = 0;

	switch (level[0])
	{
		case 'D':	if (	flag == 1	||	level == "DEBUG"	)	{(this->*fp[0])();	flag = 1;}
		case 'I':	if (	flag == 1	||	level == "INFO"		)	{(this->*fp[1])();	flag = 1;}
		case 'W':	if (	flag == 1	||	level == "WARNING"	)	{(this->*fp[2])();	flag = 1;}
		case 'E':	if (	flag == 1	||	level == "ERROR"	)	{(this->*fp[3])();	flag = 1;}	break;
		default :	std::cout << \
		"[ Probably complaining about insignificant problems ]" << std::endl; break;
	}
}
