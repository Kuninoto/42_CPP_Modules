#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;

BitcoinExchange::BitcoinExchange(void) {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &to_copy) {
	if (this != &to_copy)
		*this = to_copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &to_copy)
{
	if (this == &to_copy)
		return (*this);
	this->max_size = to_copy.max_size;
	this->storage = to_copy.storage;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {};
