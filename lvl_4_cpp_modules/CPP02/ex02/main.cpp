#include "Fixed.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	Fixed		a;
	Fixed const	b( Fixed(5.05f) * Fixed(2));

	cout << a << endl;
	cout << endl;

	cout << ++a << endl;
	cout << endl;

	cout << a << endl;
	cout << endl;

	cout << a++ << endl;
	cout << endl;

	cout << a << endl;
	cout << endl;

	cout << b << endl;
	cout << endl;

	cout << Fixed::max(a, b) << endl;

	return EXIT_SUCCESS;
}
