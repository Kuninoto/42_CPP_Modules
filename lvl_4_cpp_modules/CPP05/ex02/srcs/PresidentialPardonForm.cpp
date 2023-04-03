#include <iostream>
#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm(void) {};

PresidentialPardonForm::PresidentialPardonForm(std::string target) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	cout << "[PresidentialPardonForm] Copy Constructor called" << endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	cout << "[PresidentialPardonForm] Destructor called" << endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign) {
	return *this;
}

void PresidentialPardonForm::executeAction(void) const {
	cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" <<	endl;
}
