#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "BitcoinExchange.hpp"

using std::cout;
using std::cerr;
using std::endl;

#define BAD_INPUT_ERR "Error: bad input => "
#define FILE_OPEN_ERR "Error: could not open file"

float ft_stof(const std::string& str);

static int panic(std::string error_msg)
{
	cerr << error_msg << "\n";
	return EXIT_FAILURE;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return panic(FILE_OPEN_ERR);

	std::ifstream input_db_file(argv[1], std::ifstream::in);
	if (!input_db_file.is_open())
		return panic(FILE_OPEN_ERR);

	BitcoinExchange btc;
	std::string line;

    // skip first line
    std::getline(input_db_file, line);
    while (std::getline(input_db_file, line))
    {
        size_t delim = line.find('|');
		if (delim == std::string::npos)
		{
			cerr << BAD_INPUT_ERR << "\"" << line << "\"" << '\n';
			continue ;
		}

        std::string rate_as_str = line.substr(delim + 2);
		if (!btc.isRateInCorrectFormat(rate_as_str))
			continue;
		float rate = ft_stof(rate_as_str);

		std::string date = line.substr(0, delim - 1);
		if (!btc.isDateInCorrectFormat(date) || !btc.isValidDate(date))
			continue;

		cout << date << " => " << rate << " = " << std::setprecision(2) << rate * btc.getRateFromDataBase(date) << endl;
    }
    input_db_file.close();
	return EXIT_SUCCESS;
}
