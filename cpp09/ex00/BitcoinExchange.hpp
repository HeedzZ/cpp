#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& databaseFile);
    ~BitcoinExchange();

    float getRate(const std::string& date) const;
    bool isValidDate(const std::string& date);

private:
    std::map<std::string, float> rates;
    void loadDatabase(const std::string& databaseFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
};

#endif
