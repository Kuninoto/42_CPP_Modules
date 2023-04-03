#include <ctime>
#include <cstdlib>
#include <iostream>
#include "RobotomyRequestForm.hpp"

using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(std::string target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	*this = copy;
	cout << "[RobotomyRequestForm] Copy Constructor" << endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	cout << "[RobotomyRequestForm] Destructor called" << endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign) {
	return *this;
}

void RobotomyRequestForm::executeAction() const {

	std::srand(std::time(NULL));

	cout << "(Loud drill noises) " << endl;

	if (random() % 2 == 0)
		cout << this->getTarget() << " successfully robotomized." << endl;
	else
		cout << this->getTarget() << " failed when trying to robotimize." << endl;
}