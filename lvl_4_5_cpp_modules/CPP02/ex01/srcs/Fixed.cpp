#include <iostream>
#include "Fixed.hpp"
#include <cmath>

using std::cout;
using std::endl;

Fixed::Fixed(void) {
	cout << "Default constructor called" << endl;
	this->value = 0;
}

Fixed::Fixed(const int in_int)
{
	cout << "Int constructor called" << endl;
	this->value = in_int * (1 << Fixed::bits);
}

Fixed::Fixed(const float in_float)
{
	cout << "Float constructor called" << endl;
	this->value = roundf(in_float * (1 << Fixed::bits));
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

std::ostream &operator<<(std::ostream &out, const Fixed &nbr)
{
	out << nbr.toFloat();
	return (out);
}
