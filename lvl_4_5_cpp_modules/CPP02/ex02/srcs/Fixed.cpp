#include <iostream>
#include "Fixed.hpp"
#include <cmath>

using std::cout;
using std::endl;

Fixed::Fixed(void) {
	#ifdef LOGS
		cout << "Default constructor called" << endl;
	#endif
	this->value = 0;
}

Fixed::Fixed(const int in_int)
{
	#ifdef LOGS
		cout << "Int constructor called" << endl;
	#endif
	this->value = in_int * (1 << Fixed::bits);
}

Fixed::Fixed(const float in_float)
{
	#ifdef LOGS
		cout << "Float constructor called" << endl;
	#endif
	this->value = roundf(in_float * (1 << Fixed::bits));
}

Fixed::Fixed(const Fixed &to_copy) {
	#ifdef LOGS
		cout << "Copy constructor called" << endl;
	#endif
	this->setRawBits(to_copy.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &original)
{
	#ifdef LOGS
		cout << "Copy assignment operator called" << endl;
	#endif
	this->setRawBits(original.getRawBits());
	return (*this);
}

Fixed::~Fixed() {
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
	return Fixed( this->toFloat() + nbr.toFloat() );
}

Fixed Fixed::operator-(const Fixed &nbr) {
	return Fixed( this->toFloat() - nbr.toFloat() );
}

Fixed Fixed::operator*(const Fixed &nbr) {
	return Fixed ( this->toFloat() * nbr.toFloat() );
}

Fixed Fixed::operator/(const Fixed &nbr) {
	return Fixed ( this->toFloat() / nbr.toFloat() );
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

std::ostream &operator<<(std::ostream &out, const Fixed &nbr)
{
	out << nbr.toFloat();
	return (out);
}
