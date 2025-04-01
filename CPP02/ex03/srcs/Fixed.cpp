#include <iostream>
#include "Fixed.hpp"
#include <cmath>

using std::cout;
using std::endl;

Fixed::Fixed(void) : value(0) {
	#ifdef LOGS
		cout << "Default constructor called" << endl;
	#endif
}

Fixed::Fixed(const int inInt)
: value(inInt * (1 << Fixed::bits))
{
	#ifdef LOGS
		cout << "Int constructor called" << endl;
	#endif
}

Fixed::Fixed(const float inFloat)
: value( roundf(inFloat * (1 << Fixed::bits)) )
{
	#ifdef LOGS
		cout << "Float constructor called" << endl;
	#endif
}

Fixed::Fixed(const Fixed &to_copy) {
	#ifdef LOGS
		cout << "Copy constructor called" << endl;
	#endif
	*this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &original)
{
	#ifdef LOGS
		cout << "Copy assignment operator called" << endl;
	#endif
	this->setRawBits(original.getRawBits());
	return *this;
}

Fixed::~Fixed(void) {
	#ifdef LOGS
		cout << "Destructor called" << endl;
	#endif 
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

bool Fixed::operator>(const Fixed &nbr) {
	return this->value > nbr.getRawBits();
}

bool Fixed::operator<(const Fixed &nbr) {
	return this->value < nbr.getRawBits();
}

bool Fixed::operator<=(const Fixed &nbr) {
	return this->value <= nbr.getRawBits();
}

bool Fixed::operator>=(const Fixed &nbr) {
	return this->value >= nbr.getRawBits();
}

bool Fixed::operator==(const Fixed &nbr) {
	return this->value == nbr.getRawBits();
}

bool Fixed::operator!=(const Fixed &nbr) {
	return this->value != nbr.getRawBits();
}

Fixed Fixed::operator+(const Fixed &nbr) {
	return Fixed(this->toFloat() + nbr.toFloat());
}

Fixed Fixed::operator-(const Fixed &nbr) {
	return Fixed(this->toFloat() - nbr.toFloat());
}

Fixed Fixed::operator*(const Fixed &nbr) {
	return Fixed(this->toFloat() * nbr.toFloat());
}

Fixed Fixed::operator/(const Fixed &nbr) {
	return Fixed(this->toFloat() / nbr.toFloat());
}

// pre-increment
Fixed &Fixed::operator++(void)
{
	this->value += 1;
	return *this;
}

// post-increment
Fixed Fixed::operator++(int)
{
	// copy before increment
	Fixed tmp(this->value * toFloat());
	this->value += 1;
	return tmp;
}

// pre-decrement
Fixed &Fixed::operator--(void)
{
	this->value -= 1;
	return *this;
}

// post-decrement
Fixed Fixed::operator--(int)
{
	Fixed tmp(this->value * toFloat());
	this->value -= 1;
	return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

std::ostream& operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return stream;
}
