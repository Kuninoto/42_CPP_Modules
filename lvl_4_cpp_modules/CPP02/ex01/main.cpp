#include <cmath>
#include <cstdlib>
#include <iostream>
#include "Fixed.hpp"

using std::cout;
using std::endl;

int main(void)
{
	Fixed		a; // Default
	Fixed const b(10); // Int
	Fixed const c(42.42f); // Float
	Fixed const d(b); // Copy

	a = Fixed (1234.4321f);

	cout << "a is " << a << endl;
	cout << "b is " << b << endl;
	cout << "c is " << c << endl;
	cout << "d is " << d << endl;

	cout << "a is " << a.toInt() << " as integer" << endl;
	cout << "b is " << b.toInt() << " as integer" << endl;
	cout << "c is " << c.toInt() << " as integer" << endl;
	cout << "d is " << d.toInt() << " as integer" << endl;

	return EXIT_SUCCESS;
}
