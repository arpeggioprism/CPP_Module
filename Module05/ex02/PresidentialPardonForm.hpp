#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm(const std::string &target);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	void execute(const Bureaucrat &executor) const;
};

#endif
