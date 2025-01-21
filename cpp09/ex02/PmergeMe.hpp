#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void sort(const std::vector<int>& sequence);

private:
    void fordJohnsonSort(std::vector<int>& container);
    void fordJohnsonSort(std::deque<int>& container);

    void formPairsVector(const std::vector<int>& input, std::vector<int>& smalls, std::vector<int>& larges);
    void formPairsDeque(const std::deque<int>& input, std::deque<int>& smalls, std::deque<int>& larges);

    void insertSmallsVector(std::vector<int>& sorted, const std::vector<int>& smalls);
    void insertSmallsDeque(std::deque<int>& sorted, const std::deque<int>& smalls);

    template<typename Container>
	void printContainer(const std::string& message, const Container& container)
	{
		std::cout << message << " ";
		for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

    void printExecutionTime(const std::string& containerName, double duration);

	PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
};

#endif



