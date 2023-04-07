#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        ~BitcoinExchange(void);

        float getRateFromDataBase(const std::string& date);

        bool isDateInCorrectFormat(const std::string &date);
        bool isValidDate(const std::string& date);
        bool isRateInCorrectFormat(const std::string& rate);

    private:
        std::map<std::string, float> dataBase;
        void readDataBase(void);
};

#endif // BITCOINEXCHANGE_HPP