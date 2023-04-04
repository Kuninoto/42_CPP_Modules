#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

Intern::Intern(void) {
    #ifdef LOGS
    	cout << "[Intern] Default Constructor called" << endl;
    #endif
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
    #ifdef LOGS
	    cout << "[Intern] Copy Constructor called" << endl;
    #endif
}

Intern::~Intern() {
    #ifdef LOGS
    	cout << "[Intern] Destructor called" << endl;
    #endif
}

Intern& Intern::operator=(const Intern &assign)
{
    #ifdef LOGS
	    cout << "[Intern] Copy Assignment Operator called" << endl;
    #endif
	if (this == &assign)
        return *this;
	return *this;
}

static AForm *newShrubbery(const std::string target) {
	return new ShrubberyCreationForm(target);
}

static AForm *newRobotomy(const std::string target) {
	return new RobotomyRequestForm(target);
}

static AForm *newPresidential(const std::string target) {
	return new PresidentialPardonForm(target);
}

typedef AForm *(*FormConstructorPtr)(const std::string);

AForm *Intern::makeForm(std::string name, std::string target)
{
    AForm *choosen_form = NULL;

    const std::string form_names[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    FormConstructorPtr form_constructors[3] = {&newShrubbery, &newRobotomy, &newPresidential};

    for (size_t i = 0; i < 3; i += 1)
    {
        if (name == form_names[i])
        {
            cout << "Intern creates " << name << endl;
            choosen_form = form_constructors[i](target);;
            break ;
        }
    }
    if (!choosen_form)
        cerr << "Intern couldn't create " << name << " form" << endl;
    return choosen_form;
}