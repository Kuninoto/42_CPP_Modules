#include <iostream>
#include "Cat.hpp"

using std::cout;
using std::endl;

Cat::Cat(void) : Animal() {
	cout << "[Cat] default constructor has been called" << endl;
	this->setType("Cat");
	try {
		this->brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		cout << "[Cat] Brain memory allocation failed: " << e.what() << endl;
	}
}

Cat::Cat(const Cat &to_copy) : Animal(to_copy)
{
	this->type = to_copy.type;
	this->brain = new Brain();
	cout << "[Cat] copy constructor has been called " << endl;
}

Cat& Cat::operator=(const Cat &to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	cout << "[Cat] copy assignment constructor has been called " << endl;
	return *this;
}

Cat::~Cat(void)
{
	cout << "[Cat] default destructor has been called" << endl;
	delete this->brain;
}

void Cat::makeSound(void) const {
	cout << "Miau Miau 🐈" << endl;
}
