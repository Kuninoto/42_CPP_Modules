#include <iostream>
#include "Form.hpp"

using std::cout;
using std::endl;

Form::Form(void)
: name("DEFAULT"), grade_to_sign(1), grade_to_execute(1) {
	cout << "[Form] default constructor has been called" << endl;
}

Form::Form(string name, int grade_to_sign, int grade_to_execute) 
: name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign > LOWEST_GRADE
	|| grade_to_execute > LOWEST_GRADE)
		throw(Form::GradeTooLowException());
	else if (grade_to_sign < HIGHEST_GRADE
	|| grade_to_execute < HIGHEST_GRADE)
		throw(Form::GradeTooHighException());
	this->is_signed = false;
	cout << "[Form] <" << this->getName() << "> constructor has been called" << endl;
}

Form::~Form(void) {
	cout << "[Form] <" << this->getName() << "> default destructor has been called" << endl;
}

const string Form::getName(void) {
	return this->name;
}

bool Form::getSignState(void) {
	return this->is_signed;
}

int Form::getGradeToSign(void) {
	return this->grade_to_sign;
}

int Form::getGradeToExecute(void) {
	return this->grade_to_execute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->is_signed = true;
		bureaucrat.signForm(this->getName(), this->is_signed);
	}
	else
	{
		bureaucrat.signForm(this->getName(), this->is_signed);
		throw(Form::GradeTooLowException());
	}

}

const char* Form::GradeTooHighException::what(void) const throw() {
	return "Form exception: exception: grade too high!";
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return "Form exception: exception: grade too low!";
}

std::ostream &operator<<(std::ostream &stream, Form &form)
{
	stream << "Name: " << form.getName() << "\n"
		   << "Signed: " << (form.getSignState() == true ? "yes" : "no") << "\n"
		   << "Grade to sign: " << form.getGradeToSign() << "\n"
		   << "Grade to execute: " << form.getGradeToExecute() << "\n" 
		   << endl;
	return (stream);
}