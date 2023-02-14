#include <iostream>
#include "Cat.hpp"

using std::cout;
using std::endl;

Cat::Cat(void) : Animal("Cat") {
	cout << "[Cat] default constructor has been called" << endl;
}

Cat::Cat(const Cat &to_copy) 
{
	this->type = to_copy.type;
	cout << "[Cat] copy constructor has been called " << endl;
}

Cat& Cat::operator=(const Cat &to_copy)
{
	if (*this != to_copy)
		this->type = to_copy.type;
	cout << "[Cat] copy assignment constructor has been called " << endl;
	return *this;
}

Cat::~Cat(void) {
	cout << "[Cat] default destructor has been called" << endl;
}

Cat::makeSound(void) {
	cout << "miau miau 🐈" << endl;
}
