#include <iostream>
#include "Dog.hpp"

using std::cout;
using std::endl;

Dog::Dog(void) : Animal("Dog") {
	cout << "[Dog] default constructor has been called" << endl;
}

Dog::Dog(const Dog &to_copy) 
{
	this->type = to_copy.type;
	cout << "[Dog] copy constructor has been called " << endl;
}

Dog& Dog::operator=(const Dog &to_copy)
{
	if (*this != to_copy)
		*this = to_copy;
	cout << "[Dog] copy assignment constructor has been called " << endl;
	return *this;
}

Dog::~Dog(void) {
	cout << "[Dog] default destructor has been called" << endl;
}

Dog::makeSound(void) {
	cout << "AuAu 🐕" << endl;
}
