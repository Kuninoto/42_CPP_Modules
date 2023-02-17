#include <iostream>
#include "Dog.hpp"

using std::cout;
using std::endl;

Dog::Dog(void) : Animal() {
	cout << "[Dog] default constructor has been called" << endl;
	this->setType("Dog");
	try {
		this->brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		cout << "[Dog] Brain memory allocation failed: " << e.what() << endl;
	}
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy)
{
	this->type = to_copy.type;
	this->brain = new Brain();
	cout << "[Dog] copy constructor has been called " << endl;
}

Dog& Dog::operator=(const Dog &to_copy)
{
	if (this != &to_copy)
		*this = to_copy;
	cout << "[Dog] copy assignment constructor has been called " << endl;
	return *this;
}

Dog::~Dog(void) {
	cout << "[Dog] default destructor has been called" << endl;
	delete this->brain;
}

void Dog::makeSound(void) const {
	cout << "AuAu 🐕" << endl;
}
