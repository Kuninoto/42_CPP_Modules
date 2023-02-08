#include <cstdlib>
#include <iostream>
#include "ScavTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	ScavTrap Jubileus("Jubileus");
	ScavTrap Robert("Robert");

	Jubileus.attack("Robert");
	Robert.takeDamage(5);

	Jubileus.attack("Robert");
	Robert.takeDamage(1);

	Jubileus.attack("Robert");
	Robert.takeDamage(1);

	//Jubileus.attack("Robert");
	//Robert.takeDamage(200);

	Robert.beRepaired(7);

	Jubileus.attack("Robert");
	Robert.takeDamage(10);

	Jubileus.guardGate();
	Robert.guardGate();

	return EXIT_SUCCESS;
}
