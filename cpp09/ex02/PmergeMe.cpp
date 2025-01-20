#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>

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

void PmergeMe::sort(std::vector<int>& sequence) {
    if (sequence.empty()) {
        throw std::invalid_argument("Error: Sequence is empty.");
    }

    printContainer("Before:", sequence);

    std::vector<int> vectorContainer(sequence);
    std::deque<int> dequeContainer(sequence.begin(), sequence.end());

    clock_t start = clock();
    mergeInsertSort(vectorContainer);
    clock_t end = clock();
    printContainer("After (std::vector):", vectorContainer);
    printExecutionTime("std::vector", static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6);

    start = clock();
    mergeInsertSort(dequeContainer);
    end = clock();
    printContainer("After (std::deque):", dequeContainer);
    printExecutionTime("std::deque", static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6);
}

void PmergeMe::mergeInsertSort(std::vector<int>& container) {
    if (container.size() <= 1)
        return;

    size_t mid = container.size() / 2;
    std::vector<int> left(container.begin(), container.begin() + mid);
    std::vector<int> right(container.begin() + mid, container.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
}

void PmergeMe::mergeInsertSort(std::deque<int>& container) {
    if (container.size() <= 1)
        return;

    size_t mid = container.size() / 2;
    std::deque<int> left(container.begin(), container.begin() + mid);
    std::deque<int> right(container.begin() + mid, container.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
}

void PmergeMe::printExecutionTime(const std::string& containerName, double duration) {
    std::cout << "Time to process with " << containerName << ": " << duration << " us" << std::endl;
}
