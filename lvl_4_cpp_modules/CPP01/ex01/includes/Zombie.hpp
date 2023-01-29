#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
using std::string;

class Zombie {
    public:
        /* Destructor */
        ~Zombie(void);

        void setName(string name);

        string getName(void);

        void announce(void);
    private:
        string name;
};

/* Allocate N Zombie objects in a single allocation
and sets all their names to <name> */
Zombie  *zombieHorde(int N, string name);

#endif // ZOMBIE_HPP