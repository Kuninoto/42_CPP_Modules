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

Animal& Animal::operator=(const Animal &to_copy)
{
	if (*this != &to_copy)
		this->name = to_copy.name;
	cout << "[Animal] copy assignment constructor has been called" << endl;
	return *this;
}

Animal::~Animal(void) {
	cout << "[Animal] destructor has been called" << endl;
}
