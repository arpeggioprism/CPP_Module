#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: Form(src), _target(src._target)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
	{
		throw Form::FormNotSignedException();
	}
	else if (executor.getGrade() > this->getGradeToExecute())
	{
		throw Form::GradeTooLowException();
	}
	else
	{
		std::ofstream file;
		file.open(this->_target + "_shrubbery");
		if (file.is_open())
		{
			file << "                                                         .\n\
                                              .         ;  \n\
                 .              .              ;%     ;;   \n\
                   ,           ,                :;%  %;   \n\
                    :         ;                   :;%;'     .,   \n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;@;%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'   \n\
                        `@%.  `;@%.      ;@@%;         \n\
                          `@%%. `@%%    ;@@%;        \n\
                            ;@%. :@%%  %@@%;       \n\
                              %@@@%%%@%%%:;     \n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '         \n\
                                %@@@o%;:(.,'         \n\
                            `.. %@@@o%::;         \n\
                               `)@@@o%::;         \n\
                                %@@(o)::;        \n\
                               .%@@@@%::;         \n\
                               ;%@@@@%::;.          \n\
                              ;%@@@@%%:;;;. \n\
                          ...;%@@@@@%%:;;;;,..\n";
			file.close();
		}
		else
			std::cerr << "Error: unable to open file" << std::endl;
	}
}
