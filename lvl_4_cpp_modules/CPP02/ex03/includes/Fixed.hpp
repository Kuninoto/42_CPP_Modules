#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    public:
        // Default constructor
        Fixed(void);
        //
        Fixed(const int in_int);
        //
        Fixed(const float in_float);
        // Copy constructor
        Fixed(const Fixed &to_copy);
        // Copy assignment operator overload
        Fixed &operator=(const Fixed &original);
        // Destructor
        ~Fixed(void);

        bool operator>(const Fixed &nbr);
        bool operator<(const Fixed &nbr);
        bool operator<=(const Fixed &nbr);
        bool operator>=(const Fixed &nbr);
        bool operator==(const Fixed &nbr);
        bool operator!=(const Fixed &nbr);
        Fixed operator+(const Fixed &nbr);
        Fixed operator-(const Fixed &nbr);
        Fixed operator*(const Fixed &nbr);
		Fixed operator/(const Fixed &nbr);
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
        static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

    private:
        int value;
        static const int bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &nbr);

#endif // FIXED_HPP