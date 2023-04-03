#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", target, 145, 137) {
	cout << "[ShrubberyCreationForm] default constructor called"<< endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& to_copy)
: AForm(to_copy.getName(), to_copy.getTarget(), to_copy.getGradeToSign(), to_copy.getGradeToExecute()) {
	cout << "[ShrubberyCreationForm] copy constructor called" << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	cout << "[ShrubberyCreationForm] destructor called"<< endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	cout << "[ShrubberyCreationForm] copy assignment operator called"<< endl;
	if (this == &assign)
		return *this;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat& executor)
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSignState() == false)
		cerr << "ShrubberyCreationForm couldn't be executed by " << executor.getName() << " because it wasn't signed!" << endl;
	else
	{
		cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << endl;
		std::ofstream out;

		out.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);

		out << "\n"
			<< "                                            ." << "\n"
			<< "                                    .         ;  " << "\n"
			<< "       .              .              ;%     ;;   " << "\n"
			<< "         ,           ,                :;%  %;   " << "\n"
			<< "          :         ;                   :;%;'     .,   " << "\n"
			<< " ,.        %;     %;            ;        %;'    ,;" << "\n"
			<< "   ;       ;%;  %%;        ,     %;    ;%;    ,%'" << "\n"
			<< "    %;       %;%;      ,  ;       %;  ;%;   ,%;' " << "\n"
			<< "     ;%;      %;        ;%;        % ;%;  ,%;'" << "\n"
			<< "      `%;.     ;%;     %;'         `;%%;.%;'" << "\n"
			<< "       `:;%.    ;%%. %@;        %; ;@%;%'" << "\n"
			<< "          `:%;.  :;bd%;          %;@%;'" << "\n"
			<< "            `@%:.  :;%.         ;@@%;'   " << "\n"
			<< "              `@%.  `;@%.      ;@@%;         " << "\n"
			<< "                `@%%. `@%%    ;@@%;        " << "\n"
			<< "                  ;@%. :@%%  %@@%;       " << "\n"
			<< "                    %@bd%%%bd%%:;     " << "\n"
			<< "                      #@%%%%%:;;" << "\n"
			<< "                      %@@%%%::;" << "\n"
			<< "                      %@@@%(o);  . '         " << "\n"
			<< "                      %@@@o%;:(.,'         " << "\n"
			<< "                  `.. %@@@o%::;         " << "\n"
			<< "                     `)@@@o%::;         " << "\n"
			<< "                      %@@(o)::;        " << "\n"
			<< "                     .%@@@@%::;         " << "\n"
			<< "                     ;%@@@@%::;.          " << "\n"
			<< "                    ;%@@@@%%:;;;. " << "\n"
			<< "                ...;%@@@@@%%:;;;;,..   " << endl;
		}
}
