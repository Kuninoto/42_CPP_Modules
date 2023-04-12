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

/* Creates a Zombie instance, fill its name
private attribute, and return a pointer to it */
Zombie *newZombie(std::string name);

/* Creates a Zombie instance on randomChump() stack,
fill its name private attribute, the zombie announces itself
and then the zombie instance is dropped */
void randomChump(std::string name);

#endif // ZOMBIE_HPP