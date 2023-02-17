#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog &to_copy);
		Dog &operator=(const Dog &to_copy);
		~Dog(void);

		void makeSound(void) const;

	private:
		Brain* brain;
};

#endif // DOG_HPP