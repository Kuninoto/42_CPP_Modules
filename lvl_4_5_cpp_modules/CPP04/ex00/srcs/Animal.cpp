#include <iostream>
#include "Animal.hpp"

using std::cout;
using std::endl;

Animal::Animal(void) {
	cout << "[Animal] default constructor has been called" << endl;
};

Animal::Animal(const Animal &to_copy)
{
	this->type = to_copy.type;
	cout << "[Animal] copy constructor has been called" << endl;
}

/*
char *a;
&a <- char **;
*a <- char;
*/

/*
Animal& Animal::operator=(const Animal &to_copy)
{
	// Animal vs const Animal ^
	if (*this != to_copy)
*/

/*
Animal& Animal::operator=(const Animal &to_copy)
{
	// Animal * vs (const Animal)* ^
	if (this != &to_copy)
*/

Animal& Animal::operator=(const Animal &to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	cout << "[Animal] copy assignment constructor has been called" << endl;
	return *this;
}

Animal::~Animal(void) {
	cout << "[Animal] default destructor has been called" << endl;
}

string Animal::getType(void) const {
	return this->type;
}

void Animal::setType(string type) {
	this->type = type;
}

void Animal::makeSound(void) const {
	cout << "[Animal] makeSound() has been called" << endl;
}
