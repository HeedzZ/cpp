#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

bool isValidDate(const std::string& date) {
    // Simple validation for YYYY-MM-DD
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    return true;
}

bool isValidValue(const std::string& value) {
    try {
        float val = std::stof(value);
        return val >= 0.0f && val <= 1000.0f;
    } catch (...) {
        return false;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments." << std::endl;
        return 1;
    }

    const std::string databaseFile = argv[1]; // Assume the database file is bitcoin.csv

    try {
        BitcoinExchange btcExchange(databaseFile);
        std::ifstream inputFile(argv[1]);
        if (!inputFile.is_open())
            throw std::runtime_error("Error: could not open file.");

        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string date, valueStr;

            if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
                date.erase(remove(date.begin(), date.end(), ' '), date.end());
                valueStr.erase(remove(valueStr.begin(), valueStr.end(), ' '), valueStr.end());

                if (!isValidDate(date)) {
                    std::cerr << "Error: bad input => " << line << std::endl;
                    continue;
                }

                if (!isValidValue(valueStr)) {
                    std::cerr << "Error: not a valid value." << std::endl;
                    continue;
                }

                try {
                    float rate = btcExchange.getRate(date);
                    float value = std::stof(valueStr);
                    std::cout << date << " => " << valueStr << " = " << value * rate << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
            } else {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
