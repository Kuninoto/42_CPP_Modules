#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
using std::string;

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &to_copy);
		WrongAnimal &operator=(const WrongAnimal &to_copy);
		~WrongAnimal(void);

		string getType(void) const;
		void setType(string type);

		void makeSound(void) const;

	protected:
		string type;
};

#endif // WRONGANIMAL_HPP