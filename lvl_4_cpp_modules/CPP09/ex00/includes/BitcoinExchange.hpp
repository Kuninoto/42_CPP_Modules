#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &to_copy);
        BitcoinExchange &operator=(const BitcoinExchange& to_copy);
        ~BitcoinExchange(void);

    private:

};

#endif // BITCOINEXCHANGE_HPP