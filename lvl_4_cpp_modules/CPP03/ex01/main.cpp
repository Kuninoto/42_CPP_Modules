#include <cstdlib>
#include <iostream>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	ClapTrap Jubileus("Jubileus");
	ClapTrap Robert("Robert");

	Jubileus.attack("Robert");
	Robert.takeDamage(0);

	Jubileus.attack("Robert");
	Robert.takeDamage(0);

	Jubileus.attack("Robert");
	Robert.takeDamage(0);

	Robert.beRepaired(0);

	Jubileus.attack("Robert");
	Robert.takeDamage(0);

	return EXIT_SUCCESS;
}
