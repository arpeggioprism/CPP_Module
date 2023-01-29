#include "Intern.hpp"

int main()
{
	std::cout << "-----[Test1]	Intern::makeForm(): Success-----" << std::endl;
	{
		try
		{
			Intern someRandomIntern;
			Form *scf;
			Form *rrf;
			Form *ppf;

			scf = someRandomIntern.makeForm("shrubbery creation", "harry");
			rrf = someRandomIntern.makeForm("robotomy request", "hermione");
			ppf = someRandomIntern.makeForm("presidential pardon", "ron");

			std::cout << *scf << std::endl;
			std::cout << *rrf << std::endl;
			std::cout << *ppf << std::endl;

			delete scf;
			delete rrf;
			delete ppf;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "-----[Test2]	Intern::makeForm(): Failure-----" << std::endl;
	{
		try
		{
			Intern someRandomIntern;
			Form *nonExistentForm;

			nonExistentForm = someRandomIntern.makeForm("nonExistentForm", "name");
			std::cout << nonExistentForm << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	system("leaks a.out");
	return 0;
}