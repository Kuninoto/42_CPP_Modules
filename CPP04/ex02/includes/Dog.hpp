#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Dog : public AAnimal {
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