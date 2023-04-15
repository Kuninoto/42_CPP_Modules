#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
    public:
        /* Destructor */
        ~Zombie(void);

        void setName(std::string name);

        const std::string& getName(void) const;

        void announce(void);
    private:
        std::string name;
};

/* Allocate N Zombie objects in a single allocation
and sets all their names to <name> */
Zombie  *zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP