#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& databaseFile)
{
    loadDatabase(databaseFile);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string& databaseFile)
{
    std::ifstream file(databaseFile);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        float rate;
        if (std::getline(iss, date, ',') && iss >> rate) {
            _exchangeRates[date] = rate;
        }
    }
}

float BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
    if (it == _exchangeRates.end() || it->first != date) {
        if (it != _exchangeRates.begin())
            --it;
    }
    if (it == _exchangeRates.end() || it->first > date)
        throw std::runtime_error("Error: invalid date.");

    return it->second;
}
