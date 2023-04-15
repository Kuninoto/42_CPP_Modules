#include <iostream>
#include "Fixed.hpp"
#include <cmath>

using std::cout;
using std::endl;

Fixed::Fixed(void) : value(0) {
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int inInt)
: value(inInt * (1 << Fixed::bits)) {
	cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float inFloat)
: value( roundf(inFloat * (1 << Fixed::bits)) ) {
	cout << "Float constructor called" << endl;
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

int Fixed::getRawBits(void) const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->value / (float)(1 << Fixed::bits);
}

int Fixed::toInt(void) const {
	return this->value >> Fixed::bits;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return stream;
}
