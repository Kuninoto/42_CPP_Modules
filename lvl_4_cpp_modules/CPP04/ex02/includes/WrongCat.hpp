 #ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat &to_copy);
		WrongCat &operator=(const WrongCat &to_copy);
		~WrongCat(void);

		void makeSound(void) const;
};

#endif // WRONGCAT_HPP