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
#define INTERNAL_DB_OPEN_ERR "Error: fatal: could not open internal database file"
#define INTERNAL_DB_FILE "./data.csv"

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

	std::ifstream input_db(argv[1], std::ifstream::in);
	if (!input_db.is_open())
		return panic(FILE_OPEN_ERR);

    std::ifstream internal_db(INTERNAL_DB_FILE, std::ifstream::in);
	if (!internal_db.is_open())
		return panic(INTERNAL_DB_OPEN_ERR);

	BitcoinExchange btc;
	btc.readInternalDataBase(internal_db);

	std::string line;

    // skip first line
    std::getline(input_db, line);
    while (std::getline(input_db, line))
    {
        size_t delim = line.find('|');
		if (delim == std::string::npos
		||	line.length() < delim + 2)
		{
			cerr << BAD_INPUT_ERR << "\"" << line << "\"" << '\n';
			continue ;
		}

		std::string date = line.substr(0, delim - 1);
		if (!btc.isDateInCorrectFormat(date) || !btc.isValidDate(date))
			continue;

        std::string rate_as_str = line.substr(delim + 2);
		if (!btc.isRateInCorrectFormat(rate_as_str))
			continue;
		float rate = ft_stof(rate_as_str);

		cout << date << " => " << rate << " = " << std::setprecision(2) << rate * btc.getRateFromDataBase(date) << endl;
    }
    input_db.close();
    internal_db.close();
	return EXIT_SUCCESS;
}
