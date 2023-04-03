#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm(void)
: grade_to_sign(145), grade_to_execute(137) {
	cout << "[ShrubberyCreationForm] default constructor called"<< endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& to_copy)
: AForm(to_copy.name, to_copy.grade_to_sign, to_copy.grade_to_execute) {
	cout << "[ShrubberyCreationForm] <" << this->getName() << "> copy constructor called" << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	cout << "[ShrubberyCreationForm] destructor called"<< endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	cout << "[ShrubberyCreationForm] copy assignment operator called"<< endl;
	return *this;
}

void ShrubberyCreationForm::executeAction(void) const
{
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
