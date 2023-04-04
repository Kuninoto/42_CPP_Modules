#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Bureaucrat hermano("Hermano", LOWEST_GRADE);

	Bureaucrat ebil("Ebil", HIGHEST_GRADE);
	cout << endl;

	cout << endl;
	ShrubberyCreationForm scf("Ebil");
	PresidentialPardonForm ppf("Ebil");
	RobotomyRequestForm rrf("Ebil");
	cout << endl;

	ebil.executeForm(scf);
	scf.beSigned(ebil);
	ebil.executeForm(scf);

	cout << endl;

	ebil.executeForm(ppf);
	ppf.beSigned(ebil);
	ebil.executeForm(ppf);

	cout << endl;

	ebil.executeForm(rrf);
	rrf.beSigned(ebil);
	ebil.executeForm(rrf);

	cout << endl;

	try {
		hermano.executeForm(scf);
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
	}

	cout << endl;
	return EXIT_SUCCESS;
}