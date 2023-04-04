#include <ctime>
#include <cstdlib>
#include <iostream>
#include "RobotomyRequestForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("RobotomyRequestForm", target, 72, 45) {
	#ifdef LOGS
		cout << "[RobotomyRequestForm] Parameterized Constructor" << endl;
	#endif
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_copy)
: AForm(to_copy.getName(), to_copy.getTarget(), to_copy.getGradeToSign(), to_copy.getGradeToExecute()) {
	#ifdef LOGS
		cout << "[RobotomyRequestForm] Copy Constructor" << endl;
	#endif
}

RobotomyRequestForm::~RobotomyRequestForm() {
	#ifdef LOGS
		cout << "[RobotomyRequestForm] Destructor called" << endl;
	#endif
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &assign) {
	#ifdef LOGS
		cout << "[RobotomyRequestForm] copy assignment operator called"<< endl;
	#endif
	if (this == &assign)
		return *this;
	return *this;
}

void RobotomyRequestForm::executeSuperClassForm(Bureaucrat const& executor) const
{
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
