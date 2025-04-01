#include <iostream>
#include <cstdlib>
#include "Fixed.hpp"

using std::cout;
using std::endl;

int main(void)
{
	// DEFAULT CONSTRUCTOR
	Fixed a;
	// COPY CONSTRUCTOR
	Fixed b(a);
	// DEFAULT CONSTRUCTOR
	Fixed c;

	// COPY ASSIGNMENT OPERATOR OVERLOAD
	c = b;

	cout << a.getRawBits() << endl;
	cout << b.getRawBits() << endl;
	cout << c.getRawBits() << endl;
	return EXIT_SUCCESS;
}