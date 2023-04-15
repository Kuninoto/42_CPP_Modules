#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include "Brain.hpp"

using std::string;

class Animal {
	public:
		Animal(void);
		Animal(const Animal &to_copy);
		Animal &operator=(const Animal &to_copy);
		virtual ~Animal(void);

		string getType(void) const;
		void setType(string type);

		virtual void makeSound(void) const;

	protected:
		string type;
};

#endif // ANIMAL_HPP