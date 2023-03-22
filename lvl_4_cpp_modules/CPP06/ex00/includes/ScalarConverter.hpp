#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
using std::string;

class ScalarConverter {
	public:
		static void convert(string literal);
	private:
		static string as_char(string& literal);
		static string as_int(string& literal);
		static string as_float(string& literal);
		static string as_double(string& literal);
};

#endif // SCALARCONVERTER_HPP