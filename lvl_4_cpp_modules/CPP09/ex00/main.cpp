#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "BitcoinExchange.hpp"

using std::cerr;
using std::cout;
using std::endl;

#define ERROR_MSG_PREFFIX "Error: "
#define FILE_OPEN_ERR "Error: could not open file"
#define BAD_INPUT_ERR "Error: bad input => "
#define NOT_A_POSITIVE_ERR "Error: not a positive number."
#define TOO_LARGE_ERR "Error: too large a number."


static float ft_stof(const std::string& str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

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
    getline(input_db_file, line);
    while (std::getline(input_db_file, line))
    {
        size_t delim = line.find('|');
		if (delim == std::string::npos)
		{
			cerr << BAD_INPUT_ERR << line << "\n";
			continue ;
		}
        // set a new pair on the map <date, rate>
        std::string rate_as_str = line.substr(delim + 2, line.length());
		float rate = ft_stof(rate_as_str);

		if (rate < 0)
		{
			cerr << NOT_A_POSITIVE_ERR << '\n';
			continue ;
		}
		if (rate > 1000)
		{
			cerr << TOO_LARGE_ERR << '\n';
			continue ;
		}
		std::string date = line.substr(0, delim);
		cout << date << "=> " << rate << " = " << std::setprecision(2) << rate * btc.getRateFromDataBase(date) << endl;
    }
    input_db_file.close();
	return EXIT_SUCCESS;
}
