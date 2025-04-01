#include "Zombie.hpp"
#include <iostream> // std::cout, std::endl

using std::cout;
using std::endl;

/* Destructor */
Zombie::~Zombie(void) {
    cout << "Zombie " << this->getName() << " died 💀" << endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

const std::string& Zombie::getName(void) const {
    return this->name;
}

void Zombie::announce(void) {
    cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << endl;
}
