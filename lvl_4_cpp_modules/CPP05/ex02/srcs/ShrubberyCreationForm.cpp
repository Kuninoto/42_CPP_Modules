#include <iostream>
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
