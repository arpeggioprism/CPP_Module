#include <ostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::srand(std::time(NULL));
	{
		PresidentialPardonForm p("water");
		RobotomyRequestForm r("fire");
		ShrubberyCreationForm s("tree");

		Form *f[3] = {&p, &r, &s};
		Bureaucrat b[4] = {
			Bureaucrat("b1", 1),
			Bureaucrat("b2", 30),
			Bureaucrat("b3", 60),
			Bureaucrat("b4", 90),
		};
		for (int i = 0; i < 3; i++)
		{
			std::cout << *f[i] << std::endl;
			for (int j = 0; j < 4; j++)
			{
				b[j].signForm(*f[i]);
				b[j].executeForm(*f[i]);
				std::cout << std::endl;
			}
			std::cout << "----------------------------------------"
					  << std::endl;
		}
	}

	return 0;
}