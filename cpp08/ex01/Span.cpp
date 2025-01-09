#include "Span.hpp"
#include <iostream>
#include <limits>
#include <algorithm>


Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
	{
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (_numbers.size() >= _N)
        throw TooManyNumbersException();
    _numbers.push_back(num);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        minSpan = std::min(minSpan, span);
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    int minValue = *std::min_element(_numbers.begin(), _numbers.end());
    int maxValue = *std::max_element(_numbers.begin(), _numbers.end());
    return maxValue - minValue;
}
