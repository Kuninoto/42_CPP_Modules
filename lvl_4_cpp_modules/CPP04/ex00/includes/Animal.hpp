#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
using std::string;

class Animal {
	public:
		Animal(void);
		Animal(const Animal &to_copy);
		Animal &operator=(const Animal &to_copy);
		~Animal(void);

	protected:
		string type;
};

#endif // ANIMAL_HPP