#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);

	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &rhs);

	const std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	std::out_of_range GradeTooHighException();
	std::out_of_range GradeTooLowException();
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
