#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

struct date_t
{
    unsigned int year;
    unsigned int month;
    unsigned int day;

    bool operator==(const date_t &date) const {
        return year == date.year && month == date.month && day == date.day;
    }

    // oldest date
    bool operator<(const date_t &date)  const
    {
        if (year < date.year)
            return true;
        else if (year > date.year)
            return false;
        else // year is equal
        {
            if (month < date.month)
                return true;
            else if (month > date.month)
                return false;
            else // year and month are equal 
                return day < date.day;
        }
    }

    // most recent date
    bool operator>(const date_t &date) const
    {
        if (year > date.year)
            return true;
        else if (year < date.year)
            return false;
        else // year is equal
        {
            if (month > date.month)
                return true;
            else if (month < date.month)
                return false;
            else // year and month are equal
                return day > date.day;
        }
    }
};

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        ~BitcoinExchange(void);

        float getRateFromDataBase(const std::string& date);

    private:
        std::map<std::string, float> dataBase;
        void readDataBase(void);
};

#endif // BITCOINEXCHANGE_HPP