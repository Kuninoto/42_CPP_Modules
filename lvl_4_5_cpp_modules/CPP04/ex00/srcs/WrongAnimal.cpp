#include <iostream>
#include "WrongAnimal.hpp"

using std::cout;
using std::endl;

WrongAnimal::WrongAnimal(void) {
	cout << "[WrongAnimal] default constructor has been called" << endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &to_copy)
{
	*this = to_copy;
	cout << "[WrongAnimal] copy constructor has been called" << endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &to_copy)
{
	this->type = to_copy.type;
	cout << "[WrongAnimal] copy assignment constructor has been called" << endl;
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	cout << "[WrongAnimal] default destructor has been called" << endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}

void WrongAnimal::makeSound(void) const {
	cout << "[WrongAnimal] makeSound() has been called" << endl;
}
