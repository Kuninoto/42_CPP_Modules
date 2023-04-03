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

	//Bureaucrat hermano("Hermano", 150);

	Bureaucrat ebil("Ebil", 1);
	cout << endl;

	// AForm aform("a", "b", 0, 0);

	cout << endl;
	ShrubberyCreationForm scf("Ebil");
	PresidentialPardonForm ppf("Ebil");
	RobotomyRequestForm rrf("Ebil");
	cout << endl;

	ebil.executeForm(scf);
	scf.beSigned(ebil);
	ebil.executeForm(scf);

	cout << endl;
	return EXIT_SUCCESS;
}