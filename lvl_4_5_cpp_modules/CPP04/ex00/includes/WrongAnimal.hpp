#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &original);
		WrongAnimal &operator=(const WrongAnimal &to_copy);
		virtual ~WrongAnimal(void);

		std::string getType(void) const;
		void setType(std::string type);

		void makeSound(void) const;

	protected:
		std::string type;
};

#endif // WRONGANIMAL_HPP