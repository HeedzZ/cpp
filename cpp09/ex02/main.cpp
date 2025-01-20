#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No sequence provided." << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        std::vector<int> sequence;

        for (int i = 1; i < argc; ++i) {
            int number = std::atoi(argv[i]);
            if (number <= 0)
                throw std::invalid_argument("Error: Only positive integers are allowed.");
            sequence.push_back(number);
        }

        sorter.sort(sequence);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
