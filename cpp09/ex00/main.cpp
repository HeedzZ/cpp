#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

bool isValidDate(const std::string& date) {

    if (date.size() != 11 || date[4] != '-' || date[7] != '-')
        return false;

    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    return true;
}



void processFile(const std::string& inputFile, const BitcoinExchange& exchange) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: file is empty." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;

        if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
            if (!isValidDate(date)) {
                std::cerr << "Error: bad date => " << date << std::endl;
                continue; // Passe à la ligne suivante
            }
            try {
                std::istringstream valueStream(valueStr);
                float value;
                valueStream >> value;

                if (valueStream.fail()) {
                    std::cerr << "Error: invalid value." << std::endl;
                    continue;
                }
                else if (value > 1000) {
                    std::cerr << "Error: too large a number" << std::endl;
                    continue;
                }
                else if (value < 0) {
                    std::cerr << "Error: not a positive number." << std::endl;
                    continue;
                }

                float rate = exchange.getRate(date);
                std::cout << date << " => " << value << " = " << value * rate << std::endl;

            } catch (const std::exception& e) {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange("data.csv");
        processFile(argv[1], exchange);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
