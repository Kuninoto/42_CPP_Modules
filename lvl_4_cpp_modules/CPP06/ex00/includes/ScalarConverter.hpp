#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
using std::string;

class ScalarConverter {
	public:
		void convert(string literal);
	private:
		string as_char(string& literal);
		string as_int(string& literal);
		string as_float(string& literal);
		string as_double(string& literal);
};

#endif // SCALARCONVERTER_HPP