#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
private:
    unsigned int _N;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		if (std::distance(begin, end) + _numbers.size() > _N)
			throw TooManyNumbersException();
		_numbers.insert(_numbers.end(), begin, end);
	}

    class TooManyNumbersException : public std::exception {
        const char* what() const throw() {
            return "Too many numbers in Span";
        }
    };

    class NotEnoughNumbersException : public std::exception {
        const char* what() const throw() {
            return "Not enough numbers to calculate span";
        }
    };
};

#endif

