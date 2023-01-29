#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", 72, 45), _target("default"){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: Form(src), _target(src._target)
{
	*this = src;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
	{
		throw Form::FormNotSignedException();
	}
	else if (executor.getGrade() > this->getGradeToExecute())
	{
		throw Form::GradeTooLowException();
	}
	else
	{
		std::cout << "Drilling noises..." << std::endl;
		if (std::rand() % 2 == 0)
			std::cout << this->_target << " has been robotomized successfully"
					  << std::endl;
		else
			std::cout << "Robotomization has failed" << std::endl;
	}
}
