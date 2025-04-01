#include <cstdlib>
#include <iostream>
#include "ScavTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	ScavTrap Jubileus("Jubileus");
	ScavTrap Robert("Robert");

	cout << endl;

	Jubileus.attack("Robert");
	Robert.takeDamage(5);

	cout << endl;

	Jubileus.attack("Robert");
	Robert.takeDamage(1);

	cout << endl;

	Jubileus.attack("Robert");
	Robert.takeDamage(1);

	//Jubileus.attack("Robert");
	//Robert.takeDamage(200);

	cout << endl;

	Robert.beRepaired(7);

	cout << endl;

	Jubileus.attack("Robert");
	Robert.takeDamage(10);

	cout << endl;

	Jubileus.guardGate();
	Robert.guardGate();

	cout << endl;

	return EXIT_SUCCESS;
}
