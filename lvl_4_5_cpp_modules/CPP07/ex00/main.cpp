#include <cstdlib>
#include <iostream>
#include <string>
#include <whatever.hpp>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int a = 2;
	int b = 3;

	::swap(a, b);

	cout << "a = " << a << ", b = " << b << endl;
	cout << "min(a, b) = " << ::min(a, b) << endl;
	cout << "max(a, b) = " << ::max(a, b) << endl;

	string c = "chaine1";
	string d = "chaine2";

	::swap(c, d);

	cout << "c = " << c << ", d = " << d << endl;
	cout << "min(c, d) = " << ::min(c, d) << endl;
	cout << "max(c, d) = " << ::max(c, d) << endl;

	return EXIT_SUCCESS;
}
