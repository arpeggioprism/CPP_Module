#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) { *this = src; }

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

Form *Intern::makeForm(const std::string &formName, const std::string &target)
{
	static Form *(Intern::*formFunctions[3])(const std::string &target) = {
		&Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm,
		&Intern::makeShrubberyCreationForm};
	switch (formName[0])
	{
		case 'p':	if (formName == "presidential pardon")
					{
						std::cout << "Intern creates " << formName << std::endl;
						return (this->*formFunctions[0])(target);
					}
					break;
		case 'r':	if (formName == "robotomy request")
					{
						std::cout << "Intern creates " << formName << std::endl;
						return (this->*formFunctions[1])(target);
					}
					break;
		case 's':	if (formName == "shrubbery creation")
					{
						std::cout << "Intern creates " << formName << std::endl;
						return (this->*formFunctions[2])(target);
					}
					break;
		default :	break;
	}
	throw FormNotFoundException();
}

Form *Intern::makePresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

Form *Intern::makeRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

Form *Intern::makeShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

std::runtime_error Intern::FormNotFoundException() const
{
	return std::runtime_error("Form not found");
}
