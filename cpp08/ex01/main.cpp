#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    // Test 1: Create a Span with a capacity of 5
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception in Test 1: " << e.what() << std::endl;
    }

    // Test 2: Adding a range of iterators
    try {
        std::vector<int> moreNumbers;
        moreNumbers.push_back(1);
        moreNumbers.push_back(2);
        moreNumbers.push_back(8);
        moreNumbers.push_back(10);

        Span sp(5);
        sp.addNumbers(moreNumbers.begin(), moreNumbers.end());

        std::cout << "After adding more numbers:" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception in Test 2: " << e.what() << std::endl;
    }

    // Test 3: Test with an empty container
    try {
        Span emptySpan(5);
        std::cout << "Shortest span of empty Span: " << emptySpan.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception in Test 3 (empty Span): " << e.what() << std::endl;  // Expected: Not enough numbers to calculate span
    }

    // Test 4: Test with an attempt to add too many numbers
    try {
        Span spOverflow(5);
        spOverflow.addNumber(1);
        spOverflow.addNumber(2);
        spOverflow.addNumber(3);
        spOverflow.addNumber(4);
        spOverflow.addNumber(5);
        spOverflow.addNumber(6);
    } catch (const std::exception& e) {
        std::cout << "Exception in Test 4 (too many numbers): " << e.what() << std::endl;
    }

    // Test 5: Test with identical numbers
    try {
        Span spIdentical(5);
        spIdentical.addNumber(5);
        spIdentical.addNumber(5);
        spIdentical.addNumber(5);

        std::cout << "Shortest span with identical numbers: " << spIdentical.shortestSpan() << std::endl;
        std::cout << "Longest span with identical numbers: " << spIdentical.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception in Test 5 (identical numbers): " << e.what() << std::endl;
    }

    return 0;
}

