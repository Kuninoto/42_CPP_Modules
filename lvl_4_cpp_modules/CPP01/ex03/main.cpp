#include <cstdlib> // EXIT_* MACROS
#include <iostream> // std::string, std::cin, std::cout, std::endl
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return EXIT_SUCCESS;
}

/* A pointer can be declared as void but a reference can never be void 
So, HumanA thaat will always have a weapon takes it as a reference and
HumanB as a pointer because he may not have it */