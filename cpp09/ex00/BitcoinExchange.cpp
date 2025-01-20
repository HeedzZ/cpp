#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    loadDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    rates = other.rates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        rates = other.rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& databaseFile) {
    std::ifstream file(databaseFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        float rate;
        if (std::getline(iss, date, ',') && (iss >> rate)) {
            rates[date] = rate;
        }
    }
}

float BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = rates.lower_bound(date);
    if (it == rates.end() || it->first != date) {
        if (it == rates.begin()) {
            throw std::runtime_error("Error: no valid date found.");
        }
        --it;
    }
    return it->second;
}
