#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

using std::string;

class Zombie {
    public:
        /* Destructor */
        ~Zombie(void);

        void setName(string str);

        string getName(void);

        void announce(void);
    private:
        string name;
};

/* Creates a Zombie instance, fill its name
private attribute, and return it*/
Zombie *newZombie(string name);

/* Creates a Zombie instance, fill its name
private attribute and the zombie announces itself */
void randomChump(string name);

#endif // ZOMBIE_HPP