#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BitcoinExchange.hpp"

#define DB_FILE "./data.csv"

static unsigned int ft_stou(const std::string& str)
{
    unsigned int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

static float ft_stof(const std::string& str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

BitcoinExchange::BitcoinExchange(void) {
    this->readDataBase();
};

BitcoinExchange::~BitcoinExchange(void) {};

date_t parseDate(const std::string& date)
{
    size_t first_delim = date.find('-');
    size_t second_delim = date.find('-', first_delim + 1);
    
    return (date_t){ .year = ft_stou(date.substr(0, first_delim)),
                     .month = ft_stou(date.substr(first_delim + 1, second_delim)),
                     .day = ft_stou(date.substr(second_delim + 1))
                   };
}

static float getRateFromPreviousDate(std::map<std::string, float>& db, const std::string& date_to_search)
{
    std::map<std::string, float>::iterator itr;

    // iterate the map until a bigger date is found
    // then return the date immediatly before that
    for (itr = db.begin(); itr != db.end(); itr++)
    {
        if (parseDate(itr->first) > parseDate(date_to_search))
        {
            itr--;
            return itr->second;
        }
    }
    return 0.0f;
}

void BitcoinExchange::readDataBase(void)
{
    std::ifstream db(DB_FILE, std::ifstream::in);
    std::string line;
    size_t delim;

    // skip first line
    getline(db, line);
    while (std::getline(db, line))
    {
        delim = line.find(',');
        // set a new pair on the map <date, rate>
        std::string rate = line.substr(delim + 1, line.length());
        this->dataBase[line.substr(0, delim)] = ft_stof(rate);
    }
    db.close();
}

float BitcoinExchange::getRateFromDataBase(const std::string& date)
{
    if (this->dataBase.count(date) > 0)
        return this->dataBase.at(date);
    return getRateFromPreviousDate(this->dataBase, date);
}
