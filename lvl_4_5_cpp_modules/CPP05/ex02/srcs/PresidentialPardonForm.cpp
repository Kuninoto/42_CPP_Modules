#include <iostream>
#include "PresidentialPardonForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", target, 25, 5) {
	#ifdef LOGS
		cout << "[PresidentialPardonForm] Parameterized Constructor called" << endl;
	#endif
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: AForm(copy.getName(), copy.getTarget(), copy.getGradeToSign(), copy.getGradeToExecute()) {
	#ifdef LOGS
		cout << "[PresidentialPardonForm] Copy Constructor called" << endl;
	#endif
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	#ifdef LOGS
		cout << "[PresidentialPardonForm] Destructor called" << endl;
	#endif
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &assign) {
	#ifdef LOGS
		cout << "[PresidentialPardonForm] Copy Assignment Operator called" << endl;
	#endif
	if (this == &assign)
		return *this;
	return *this;
}

void PresidentialPardonForm::executeSuperClassForm(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSignState() == false)
		cerr << "PresidentialPardonForm couldn't be executed by " << executor.getName() << " because it wasn't signed!" << endl;
	else
		cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << endl;
}
