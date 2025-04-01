#include <iostream>
#include "AAnimal.hpp"

using std::cout;
using std::endl;

AAnimal::AAnimal(void) {
	cout << "[AAnimal] default constructor has been called" << endl;
}

AAnimal::AAnimal(const AAnimal &to_copy)
{
	this->type = to_copy.type;
	cout << "[AAnimal] copy constructor has been called" << endl;
}

AAnimal& AAnimal::operator=(const AAnimal &to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	cout << "[AAnimal] copy assignment constructor has been called" << endl;
	return *this;
}

AAnimal::~AAnimal(void) {
	cout << "[AAnimal] default destructor has been called" << endl;
}

std::string AAnimal::getType(void) const {
	return this->type;
}

void AAnimal::setType(std::string type) {
	this->type = type;
}

void AAnimal::makeSound(void) const {
	cout << "[AAnimal] makeSound() has been called" << endl;
}
