#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &src)
	: Form(src), _target(src._target)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
	PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw Form::GradeTooLowException();
	else
		std::cout << _target << " has been pardoned by Zafod Beeblebrox."
				  << std::endl;
}
