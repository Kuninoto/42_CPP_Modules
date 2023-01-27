#include "Zombie.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

Zombie::~Zombie()
{
    cout << "Zombie " << getName() << " died 💀" << endl;
}

void Zombie::setName(string str) {
    name = str;
}

string Zombie::getName(void) {
    return name;
}

void Zombie::announce(void) {
    cout << getName() << ": BraiiiiiiinnnzzzZ..." << endl;
}
