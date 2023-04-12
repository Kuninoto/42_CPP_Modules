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
    std::string input;

    /* STACK */
    cout << "Name the stacked Zombie 🧟‍♂️: ";
    getline(cin, input);
    if (cin.eof() == true)
    {
        cin.clear();
        clearerr(stdin);
		cout << endl;
    }
    
    randomChump(input);

    /* HEAP ZOMBIE */
    cout << "Name the heap Zombie 🧟‍♂️: ";
    getline(cin, input);
    if (cin.eof() == true)
    {
        cin.clear();
        clearerr(stdin);
	    cout << endl;
    }

    Zombie *new_zombie = newZombie(input);
    /* Upon main() exit, if new_zombie is not deleted
    the destructor is not called, causing a memory leak */
    delete new_zombie;

    return EXIT_SUCCESS;
}
