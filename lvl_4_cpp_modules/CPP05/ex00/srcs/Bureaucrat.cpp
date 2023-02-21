#include "Bureaucrat.hpp"

using std::cout;
using std::cerr;
using std::endl;

Bureaucrat::Bureaucrat(void) {
	cout << "[Bureaucrat] default constructor has been called" << endl;
};

Bureaucrat::Bureaucrat(string name, int grade) : name(name)
{
	if (grade < HIGHEST_GRADE)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > LOWEST_GRADE)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->grade = grade;
	cout << "[Bureaucrat] <" << this->getName() << "> constructor called" << endl;
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &original)
{
	this->grade = original.grade;
	cout << "[Bureaucrat] <" << this->getName() << "> copy constructor called" << endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	cout << "[Bureaucrat] <" << this->getName() << "> default destructor has been called" << endl;
};

string const Bureaucrat::getName(void) {
	return this->name;
}

int Bureaucrat::getGrade(void) {
	return this->grade;
}

void Bureaucrat::setGrade(int grade) {
	if (grade > LOWEST_GRADE)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < HIGHEST_GRADE)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->grade = grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (grade - 1 < HIGHEST_GRADE)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->grade -= 1;
}

void Bureaucrat::decrementGrade(void)
{
	if (grade + 1 > LOWEST_GRADE)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->grade += 1;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat exception: grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat exception: grade too low!";
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat)
{
	stream << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return (stream);
}
