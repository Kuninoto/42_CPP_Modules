#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
		// Default constructor
		Fixed(void);
		// Copy constructor
		Fixed(const Fixed &to_copy);
		// Copy assignment operator overload
		Fixed &operator=(const Fixed &original);
		// Destructor
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int value;
		static const int bits = 8;
};

#endif // FIXED_HPP