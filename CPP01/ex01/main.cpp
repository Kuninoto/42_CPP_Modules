#include <cstdlib> // EXIT_* MACROS
#include <iostream> // std::cin, std::cout, std::endl
#include <string>
#include <stdio.h>
#include "Zombie.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    std::string zombies_name;
    int n;

    while (1)
    {
        cout << "Name the Zombies 🧟‍♂️: ";
        getline(cin, zombies_name);
        if (cin.eof() == true)
        {
            cin.clear();
            clearerr(stdin);
			cout << endl;
        }
        if (!zombies_name.empty())
            break;
        cout << "Please insert a name for the zombies" << endl;
    }

    cout << "How much zombies you'd like to have?" << endl;
    cin >> n;

    Zombie  *zombie_army = zombieHorde(n, zombies_name);

    for (int i = 0; i < n; i += 1)
        zombie_army[i].announce();

    delete[]  zombie_army;
    return EXIT_SUCCESS;
}