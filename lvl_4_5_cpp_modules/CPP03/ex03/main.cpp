#include <cstdlib>
#include <iostream>
#include "DiamondTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
    DiamondTrap Bozo("Bozo");
    DiamondTrap Rato("Rato");
    DiamondTrap	Clone;

    cout << endl;

    Rato.attack("Bozo");
    Bozo.takeDamage(30);

    cout << endl;

    Rato.attack("Bozo");
    Bozo.takeDamage(30);

    cout << endl;

    Rato.attack("Bozo");
    Bozo.takeDamage(30);

    cout << endl;

    Clone = Bozo;

    cout << endl;

    Rato.attack("Bozo Clone");
    Clone.takeDamage(30);

    cout << endl;

    Rato.guardGate();

    cout << endl;

    Clone.beRepaired(100);
    Clone.highFivesGuys();

    cout << endl;

    Rato.whoAmI();

    cout << endl;

    return EXIT_SUCCESS;
}
