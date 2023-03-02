#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal {
	public:
		Cat(void);
		Cat(const Cat &to_copy);
		Cat &operator=(const Cat &to_copy);
		~Cat(void);

		void makeSound(void) const;

	private:
		Brain* brain;
};

#endif // CAT_HPP