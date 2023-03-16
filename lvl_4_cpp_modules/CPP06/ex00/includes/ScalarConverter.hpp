#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <limits>
# include <iostream>
# include <string>
using std::string;

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &to_copy);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter &original);
		
		void convert(string literal);
	private:

};

#endif // SCALARCONVERTER_HPP