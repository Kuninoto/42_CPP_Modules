#include <iostream>
#include "Dog.hpp"

using std::cout;
using std::endl;

Dog::Dog(void) : Animal() {
	cout << "[Dog] default constructor has been called" << endl;
	this->setType("Dog");
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy)
{
	*this = to_copy;
	cout << "[Dog] copy constructor has been called " << endl;
}

Dog& Dog::operator=(const Dog &to_copy)
{
	*this = to_copy;
	cout << "[Dog] copy assignment constructor has been called " << endl;
	return *this;
}

Dog::~Dog(void) {
	cout << "[Dog] default destructor has been called" << endl;
}

void Dog::makeSound(void) const {
	cout << "AuAu 🐕" << endl;
}
