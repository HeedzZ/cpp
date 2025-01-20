#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>

class PmergeMe {
public:
    PmergeMe();                            
    ~PmergeMe();

    void sort(std::vector<int>& sequence);

private:
    void mergeInsertSort(std::vector<int>& container);
    void mergeInsertSort(std::deque<int>& container);

    template<typename Container>
	void PmergeMe::printContainer(const std::string& message, const Container& container) {
		std::cout << message << " ";
		for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

    void printExecutionTime(const std::string& containerName, double duration);

	PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
};

#endif
