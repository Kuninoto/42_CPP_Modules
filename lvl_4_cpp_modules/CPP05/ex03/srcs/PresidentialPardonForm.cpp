#include <iostream>
#include "PresidentialPardonForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", target, 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: AForm(copy.getName(), copy.getTarget(), copy.getGradeToSign(), copy.getGradeToExecute()) {
	cout << "[PresidentialPardonForm] Copy Constructor called" << endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	cout << "[PresidentialPardonForm] Destructor called" << endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &assign) {
	if (this == &assign)
		return *this;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat &executor)
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSignState() == false)
		cerr << "PresidentialPardonForm couldn't be executed by " << executor.getName() << " because it wasn't signed!" << endl;
	else
		cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << endl;
}