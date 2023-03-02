#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include "Brain.hpp"

using std::string;

class AAnimal {
	public:
		AAnimal(void);
		AAnimal(const AAnimal &to_copy);
		AAnimal &operator=(const AAnimal &to_copy);
		virtual ~AAnimal(void);

		string getType(void) const;
		void setType(string type);

		virtual void makeSound(void) const = 0;

	protected:
		string type;
};

#endif // AANIMAL_HPP