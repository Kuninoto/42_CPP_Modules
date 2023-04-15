#include <iostream>
#include "Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed(void)
{
	cout << "Default constructor called" << endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &to_copy) {
	cout << "Copy constructor called" << endl;
	this->setRawBits(to_copy.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &original)
{
	cout << "Copy assignment operator called" << endl;
	this->setRawBits(original.getRawBits());
	return (*this);
}

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
};

int Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}
