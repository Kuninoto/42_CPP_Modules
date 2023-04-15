#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		// Default constructor
		Fixed(void);
		// Parametrized Constructors
		Fixed(const int inInt);
		Fixed(const float inFloat);
		// Copy constructor
		Fixed(const Fixed &to_copy);
		// Copy assignment operator overload
		Fixed &operator=(const Fixed &original);
		// Destructor
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

	private:
		int value;
		static const int bits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);

#endif // FIXED_HPP