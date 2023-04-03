#include <cstdlib>
#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	AForm *a;
	AForm *b;
	AForm *c;

	Intern Arnaldo;

	a = Arnaldo.makeForm("robotomy request", "Ebil");
	b = Arnaldo.makeForm("presidential pardon", "Ebil");
	c = Arnaldo.makeForm("shrubbery creation", "Ebil");

	Arnaldo.makeForm("foo", "Ebil");

	delete a;
	delete b;
	delete c;
	return EXIT_SUCCESS;
}