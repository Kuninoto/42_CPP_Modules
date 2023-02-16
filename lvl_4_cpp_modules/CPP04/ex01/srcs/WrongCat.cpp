#include <iostream>
#include "WrongCat.hpp"

using std::cout;
using std::endl;

WrongCat::WrongCat(void) : WrongAnimal() {
	cout << "[WrongCat] default constructor has been called" << endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &to_copy) : WrongAnimal(to_copy)
{
	this->type = to_copy.type;
	cout << "[WrongCat] copy constructor has been called " << endl;
}

WrongCat& WrongCat::operator=(const WrongCat &to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	cout << "[WrongCat] copy assignment constructor has been called " << endl;
	return *this;
}

WrongCat::~WrongCat(void) {
	cout << "[WrongCat] default destructor has been called" << endl;
}

void WrongCat::makeSound(void) const {
	cout << "Miau Miau 🐈" << endl;
}