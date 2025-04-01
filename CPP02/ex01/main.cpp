#include <cstdlib>
#include <iostream>
#include "Fixed.hpp"

using std::cout;
using std::endl;

int main(void)
{
	// DEFAULT CONSTRUCTOR
	Fixed		a;
	// INT CONSTRUCTOR
	Fixed const b(10);
	// FLOAT CONSTRUCTOR
	Fixed const c(42.42f);
	// COPY CONSTRUCTOR
	Fixed const d(b);

	cout << endl;

	// COPY ASSIGNMENT OPERATOR
	a = Fixed (1234.4321f);
	cout << endl;

	cout << "a is " << a << endl;
	cout << "b is " << b << endl;
	cout << "c is " << c << endl;
	cout << "d is " << d << endl;

	cout << endl;

	cout << "a is " << a.toInt() << " as integer" << endl;
	cout << "b is " << b.toInt() << " as integer" << endl;
	cout << "c is " << c.toInt() << " as integer" << endl;
	cout << "d is " << d.toInt() << " as integer" << endl;

	cout << endl;
	return EXIT_SUCCESS;
}
