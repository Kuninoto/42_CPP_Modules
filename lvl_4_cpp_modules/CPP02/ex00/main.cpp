#include <iostream>
#include <cstdlib>
#include "Fixed.hpp"

using std::cout;
using std::endl;

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	cout << a.getRawBits() << endl;
	cout << b.getRawBits() << endl;
	cout << c.getRawBits() << endl;
	return EXIT_SUCCESS;
}