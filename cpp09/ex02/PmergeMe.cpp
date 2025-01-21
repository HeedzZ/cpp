#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    (void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort(const std::vector<int>& sequence) {
    if (sequence.empty()) {
        throw std::invalid_argument("Error: Sequence is empty.");
    }

    std::vector<int> vectorContainer(sequence.begin(), sequence.end());
    std::deque<int> dequeContainer(sequence.begin(), sequence.end());

    printContainer("Before:", vectorContainer);

    clock_t start = clock();
    fordJohnsonSort(vectorContainer);
    clock_t end = clock();
    printContainer("After (std::vector):", vectorContainer);
    printExecutionTime("std::vector", static_cast<double>(end - start) / CLOCKS_PER_SEC);

    start = clock();
    fordJohnsonSort(dequeContainer);
    end = clock();
    printContainer("After (std::deque):", dequeContainer);
    printExecutionTime("std::deque", static_cast<double>(end - start) / CLOCKS_PER_SEC);
}

void PmergeMe::fordJohnsonSort(std::vector<int>& container) {
    if (container.size() <= 1)
        return;

    std::vector<int> smalls;
    std::vector<int> larges;

    formPairsVector(container, smalls, larges);
    fordJohnsonSort(larges);
    insertSmallsVector(larges, smalls);

    container = larges;
}

void PmergeMe::fordJohnsonSort(std::deque<int>& container) {
    if (container.size() <= 1)
        return;

    std::deque<int> smalls;
    std::deque<int> larges;

    formPairsDeque(container, smalls, larges);
    fordJohnsonSort(larges);
    insertSmallsDeque(larges, smalls);
    container = larges;
}

void PmergeMe::formPairsVector(const std::vector<int>& input, std::vector<int>& smalls, std::vector<int>& larges) {
    for (size_t i = 0; i < input.size(); i += 2) {
        if (i + 1 < input.size()) {
            if (input[i] < input[i + 1]) {
                smalls.push_back(input[i]);
                larges.push_back(input[i + 1]);
            } else {
                smalls.push_back(input[i + 1]);
                larges.push_back(input[i]);
            }
        } else {
            smalls.push_back(input[i]);
        }
    }
}

void PmergeMe::formPairsDeque(const std::deque<int>& input, std::deque<int>& smalls, std::deque<int>& larges) {
    for (size_t i = 0; i < input.size(); i += 2) {
        if (i + 1 < input.size()) {
            if (input[i] < input[i + 1]) {
                smalls.push_back(input[i]);
                larges.push_back(input[i + 1]);
            } else {
                smalls.push_back(input[i + 1]);
                larges.push_back(input[i]);
            }
        } else {
            smalls.push_back(input[i]);
        }
    }
}

void PmergeMe::insertSmallsVector(std::vector<int>& sorted, const std::vector<int>& smalls) {
    for (size_t i = 0; i < smalls.size(); ++i) {
        std::vector<int>::iterator position = std::upper_bound(sorted.begin(), sorted.end(), smalls[i]);
        sorted.insert(position, smalls[i]);
    }
}

void PmergeMe::insertSmallsDeque(std::deque<int>& sorted, const std::deque<int>& smalls) {
    for (size_t i = 0; i < smalls.size(); ++i) {
        std::deque<int>::iterator position = std::upper_bound(sorted.begin(), sorted.end(), smalls[i]);
        sorted.insert(position, smalls[i]);
    }
}

void PmergeMe::printExecutionTime(const std::string& containerName, double duration) {
    std::cout << "Time to process with " << containerName << ": " << duration << " us" << std::endl;
}
