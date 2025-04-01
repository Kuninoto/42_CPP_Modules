#include <iostream>
#include "Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed(void) : value(0) {
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &to_copy) {
	cout << "Copy constructor called" << endl;
	*this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &original)
{
	cout << "Copy assignment operator called" << endl;
	this->setRawBits(original.getRawBits());
	return *this;
}

Fixed::~Fixed(void) {
	cout << "Destructor called" << endl;
};

int Fixed::getRawBits(void) const
{
	cout << "getRawBits() member function called" << endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}
