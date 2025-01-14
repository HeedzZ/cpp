#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, float> _exchangeRates;
    void loadDatabase( const std::string& databaseFile);
public:
    BitcoinExchange(const std::string& databaseFile);
    ~BitcoinExchange();

    float getRate(const std::string& date) const;
};

#endif
