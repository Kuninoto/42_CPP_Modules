#include <iostream>
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm(void)
: grade_to_sign(145), grade_to_execute(137) {
	cout << "ShrubberyCreationForm default constructor called"<< endl;
};


ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	cout << "ShrubberyCreationForm destructor called"<< endl;
};
