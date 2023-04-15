#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

Base *generate(void)
{
	srand(time(NULL));
	char c = "ABC"[rand() % 3];

	cout << "Type " << c << " created!" << endl;
	switch (c)
	{
		case 'A':
			return new A;
		case 'B':
			return new B;
		case 'C':
			return new C;
	}
	return NULL;
}

void identify(Base *p)
{
	// just to shut "unused-value" compiler warning
	bool sucessfully_casted;

	cout << "Identify with Base *: ";

	sucessfully_casted = dynamic_cast<A *>(p);
	if (sucessfully_casted)
	{
		cout << "A" << endl;
		return ;
	}
	sucessfully_casted = dynamic_cast<B *>(p);
	if (sucessfully_casted)
	{
		cout << "B" << endl;
		return ;
	}
	sucessfully_casted = dynamic_cast<C *>(p);
	if (sucessfully_casted)
	{
		cout << "C" << endl;
		return ;
	}
	if (!sucessfully_casted)
		cout << "Invalid type" << endl;
}

void identify(Base &p)
{
	cout << "Identify with Base &: ";
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		cout << "A" << endl;
	}
	catch (const std::exception& e) {
		try {
			B &b = dynamic_cast<B &>(p);
			(void)b;
			cout << "B" << endl;
		}
		catch (const std::exception& e) {
			try {
				C &c = dynamic_cast<C &>(p);
				(void)c;
				cout << "C" << endl;
			}
			catch (const std::exception& e) {
				cout << "Invalid type" << endl;
			}
		}
	}
}
