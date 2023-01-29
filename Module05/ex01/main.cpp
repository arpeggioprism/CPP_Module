#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "------------------Test------------------" << std::endl;
	{
		Bureaucrat harry("Harry", 42);
		Form low("Low", 150, 1);
		Form equal("Equal", 42, 1);
		Form high("High", 1, 1);

		std::cout << harry << std::endl;
		harry.signForm(low);
		harry.signForm(equal);
		harry.signForm(high);
	}
	system("leaks a.out");
}