#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	Form();
	Form(const std::string &name, const int gradeToSign,
		 const int gradeToExecute);
	Form(Form const &src);
	~Form();
	Form &operator=(Form const &rhs);

	const std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat &bureaucrat);

	std::out_of_range GradeTooHighException() const;
	std::out_of_range GradeTooLowException() const;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif
