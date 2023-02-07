#include <cstdlib>
#include <iostream>
#include "BSP.hpp"

using std::cout;
using std::endl;

/* https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/ */

int main(void)
{
	if (bsp(Point(0, 0), Point(20, 0), Point(10, 30), Point(10, 15)) == true)
        cout << "Point is in the triangle" << endl;
	else
        cout << "Point is not in the triangle" << endl;
	return EXIT_SUCCESS;
}
