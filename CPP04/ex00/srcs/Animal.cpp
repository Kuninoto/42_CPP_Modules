#include <iostream>
#include "Animal.hpp"

using std::cout;
using std::endl;

Animal::Animal(void) {
	cout << "[Animal] default constructor has been called" << endl;
};

Animal::Animal(const Animal &to_copy)
{
	*this = to_copy;
	cout << "[Animal] copy constructor has been called" << endl;
}

Animal& Animal::operator=(const Animal &to_copy)
{
	this->type = to_copy.type;
	cout << "[Animal] copy assignment constructor has been called" << endl;
	return *this;
}

Animal::~Animal(void) {
	cout << "[Animal] default destructor has been called" << endl;
}

std::string Animal::getType(void) const {
	return this->type;
}

void Animal::setType(std::string type) {
	this->type = type;
}

void Animal::makeSound(void) const {
	cout << "[Animal] makeSound() has been called" << endl;
}
