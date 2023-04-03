#include <ctime>
#include <cstdlib>
#include <iostream>
#include "RobotomyRequestForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("RobotomyRequestForm", target, 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_copy)
: AForm(to_copy.getName(), to_copy.getTarget(), to_copy.getGradeToSign(), to_copy.getGradeToExecute()) {
	cout << "[RobotomyRequestForm] Copy Constructor" << endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	cout << "[RobotomyRequestForm] Destructor called" << endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &assign) {
	cout << "[RobotomyRequestForm] copy assignment operator called"<< endl;
	if (this == &assign)
		return *this;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat &executor) {

	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSignState() == false)
		cerr << "RobotomyRequestForm couldn't be executed by " << executor.getName() << " because it wasn't signed!" << endl;
	else
	{
		std::srand(std::time(NULL));

		cout << "(Loud drill noises) " << endl;

		if (random() % 2 == 0)
			cout << this->getTarget() << " successfully robotomized." << endl;
		else
			cout << this->getTarget() << " failed when trying to robotimize." << endl;
	}
}