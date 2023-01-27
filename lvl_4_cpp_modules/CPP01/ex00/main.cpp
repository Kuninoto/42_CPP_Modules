#include "Zombie.hpp"
#include <cstdlib> // EXIT_* MACROS
#include <iostream> // std::string, std::cin, std::cout, std::endl

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    string input;

    /* STACK */
    cout << "Name a Zombie 🧟‍♂️: ";
    getline(cin, input);
    
    randomChump(input);

    /* HEAP ZOMBIE */
    cout << "Name a Zombie 🧟‍♂️: ";
    getline(cin, input);

    Zombie *new_zombie = newZombie(input);
    /* Upon main() exit, if new_zombie is not deleted
    the destructor is not called, causing a memory leak */
    delete new_zombie;

    return EXIT_SUCCESS;
}
