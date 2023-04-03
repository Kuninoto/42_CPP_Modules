#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

using std::cout;
using std::endl;

Intern::Intern(void) {
	cout << "[Intern] Default Constructor called" << endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
	cout << "[Intern] Copy Constructor called" << endl;
}

Intern::~Intern() {
	cout << "[Intern] Destructor called" << endl;
}

Intern& Intern::operator=(const Intern &assign)
{
	if (this == &assign)
        return *this;
	return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    AForm *choosen_form = NULL;

    std::string form_names[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    AForm*    forms[] = {
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
        new ShrubberyCreationForm(target)
    };

    for (size_t i = 0; i < 3; i += 1)
    {
        if (name == form_names[i])
        {
            cout << "Intern creates " << name << endl;
            choosen_form  = forms[i];
        }
        else
            delete forms[i];
    }
    if (choosen_form == NULL)
        cout << "Intern couldn't create " << name << " form" << endl;
    return choosen_form;
}