#include "Bureaucrat.hpp"

using std::cout;
using std::cerr;
using std::endl;

Bureaucrat::Bureaucrat(void) {
	#ifdef LOGS
		cout << "[Bureaucrat] default constructor has been called" << endl;
	#endif
};

Bureaucrat::Bureaucrat(const Bureaucrat& to_copy)
{
	if (this != &to_copy)
		*this = to_copy;
	#ifdef LOGS
		cout << "[Bureaucrat] <" << this->getName() << "> copy constructor called" << endl;
	#endif
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	#ifdef LOGS
		cout << "[Bureaucrat] <" << this->getName() << "> constructor called" << endl;
	#endif
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &original)
{
	const_cast<std::string&>(this->name) = original.name;
	this->grade = original.grade;
	#ifdef LOGS
		cout << "[Bureaucrat] <" << this->getName() << "> copy assignment operator called" << endl;
	#endif
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	#ifdef LOGS
		cout << "[Bureaucrat] <" << this->getName() << "> default destructor has been called" << endl;
	#endif
};

const std::string& Bureaucrat::getName(void) const {
	return this->name;
}

int Bureaucrat::getGrade(void) const {
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
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade -= 1;
}

void Bureaucrat::decrementGrade(void)
{
	if (grade + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade += 1;
}

void Bureaucrat::signForm(std::string form_name, bool is_signed)
{
	if (is_signed)
		cout << this->getName() << " signed " << form_name << endl;
	else
		cout << this->getName() << " couldn't sign " << form_name
			 << " because the grade was too low 🥺" << endl;
}

void Bureaucrat::executeForm(AForm const& form) {
	form.execute(*this);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat exception: grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat exception: grade too low!";
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat)
{
	stream << Bureaucrat.getName() 
		   << "Grade: " << Bureaucrat.getGrade();
	return stream;
}
