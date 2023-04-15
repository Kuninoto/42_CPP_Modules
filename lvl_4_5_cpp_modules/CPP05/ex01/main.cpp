#include <cstdlib>
#include "Form.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main(void)
{
	cout << "GENERAL" << endl;
	{
		// Constructor
		Form	a("Contract", 42, 42);
		// Copy Constructor
		Form	b(a);
		// Copy assignment
		Form	c = b;

		// ostream overload
		cout << "a:\n" << a << endl;
		cout << "b:\n" << b << endl;
		cout << "c:\n" << c << endl;
	}

	cout << endl;

	{
		cout << "TEST 1" << endl;
		try
		{
			// Grade too low
			Form	a("A", LOWEST_GRADE + 1, LOWEST_GRADE - 1);
			cout << a << endl;
		}
		catch (std::exception& e) {
			cerr << e.what() << endl;
		}

		cout << endl;

		cout << "TEST 2" << endl;
		try
		{
			// Grade too high
			Form	b("B", HIGHEST_GRADE - 1, 42);
			cout << b << endl;
		}
		catch (std::exception& e) {
			cerr << e.what() << endl;
		}

		cout << endl;

		cout << "TEST 3" << endl;
		try
		{
			// Able to sign all forms
			Bureaucrat	s1("Student1", HIGHEST_GRADE);
			cout << s1 << endl;

			Form	c1("C1", HIGHEST_GRADE, 2);
			Form	c2("C2", 90, LOWEST_GRADE);
			cout << c1 << endl;
			cout << c2 << endl;

			c1.beSigned(s1);
			c2.beSigned(s1);
			c1.beSigned(s1);

			cout << c1 << endl;
			cout << c2 << endl;
		}
		catch (std::exception& e) {
			cerr << e.what() << endl;
		}

		cout << endl;

		cout << "TEST 4" << endl;
		try
		{
			// Unable to sign any form
			Bureaucrat	s2("Student2", LOWEST_GRADE);
			cout << s2 << endl;

			Form	c3("C3", HIGHEST_GRADE, 2);
			cout << c3 << endl;

			// Exception will be thrown
			c3.beSigned(s2);
			cout << c3 << endl;
		}
		catch (std::exception& e) {
			cerr << e.what() << endl;
		}
	}
	return EXIT_SUCCESS;
}
