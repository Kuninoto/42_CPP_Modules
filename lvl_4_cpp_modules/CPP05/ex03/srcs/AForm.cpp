#include "AForm.hpp"

using std::cout;
using std::endl;

AForm::AForm(std::string name, std::string target, int grade_to_sign, int grade_to_execute)
: name(name), target(target), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	cout << "[AForm] Parameterized constructor called" << endl;
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	else if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
}

AForm::~AForm() {
	cout << "[AForm] Destructor called" << endl;
}

AForm::AForm(AForm& to_copy)
: name(to_copy.getName()), target(to_copy.getTarget()), is_signed(to_copy.getSignState()), grade_to_sign(to_copy.getGradeToSign()), grade_to_execute(to_copy.getGradeToExecute()) {
	cout << "[AForm] Copy Constructor called" << endl;
}

AForm& AForm::operator=(AForm& original) {
	this->is_signed = original.getSignState();
	return *this;
}

std::string AForm::getName(void) const {
	return this->name;
}

std::string AForm::getTarget(void) const {
	return this->target;
}

int AForm::getGradeToSign(void) const {
	return this->grade_to_sign;
}

int AForm::getGradeToExecute(void) const {
	return this->grade_to_execute;
}

bool AForm::getSignState(void) {
	return this->is_signed;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->is_signed = true;
		bureaucrat.signForm(this->getName(), this->is_signed);
	}
	else
	{
		bureaucrat.signForm(this->getName(), this->is_signed);
		throw AForm::GradeTooLowException();
	}
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "AForm exception: grade too high!";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "AForm exception: grade too low!";
}

std::ostream & operator<<(std::ostream& stream, AForm& form)
{
	stream << "AForm: " << form.getName() 
		   << "Grade to sign: " << form.getGradeToSign()
		   << "Grade to execute: " << form.getGradeToExecute()
		   << "Signed state:" << form.getSignState();
	return stream;
}
