#include "Bureaucrat.hpp"

int main()
{
	std::cout << "NormalTest" << std::endl;
	{
		Bureaucrat b("Normal", 75);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
	}
	std::cout << std::endl;


	std::cout << "ConstructerTooLowTest" << std::endl;
	try
	{
		Bureaucrat test("test", 200);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "ConstructerTooHighTest" << std::endl;
	try
	{
		Bureaucrat test("test", 0);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;


	std::cout << "TooHighTest" << std::endl;
	{
		Bureaucrat b("HIGH", 1);
		std::cout << b;
		try
		{
			b.incrementGrade();
			std::cout << b;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "TooLowTest" << std::endl;
	{
		Bureaucrat b("LOW", 150);
		std::cout << b;
		try
		{
			b.decrementGrade();
			std::cout << b;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;


	system("leaks a.out");
	return 0;
}
