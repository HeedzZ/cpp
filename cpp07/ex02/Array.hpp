#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* array;
    unsigned int len;

public:
    Array() : array(NULL), len(0) {}

    Array(unsigned int n) : array(new T[n]()), len(n) {}

    Array(const Array& other) : array(new T[other.len]), len(other.len)
	{
        for (unsigned int i = 0; i < len; ++i)
            array[i] = other.array[i];
    }

    Array& operator=(const Array& other)
	{
        if (this != &other)
		{
            delete[] array;
            len = other.len;
            array = new T[len];
            for (unsigned int i = 0; i < len; ++i)
                array[i] = other.array[i];
        }
        return *this;
    }

    ~Array()
	{
        delete[] array;
    }

    T& operator[](unsigned int i)
	{
        if (i >= len)
            throw std::out_of_range("Index hors limites");
        return array[i];
    }

    const T& operator[](unsigned int i) const
	{
        if (i >= len)
            throw std::out_of_range("Index hors limites");
        return array[i];
    }

    unsigned int size() const
	{
        return len;
    }
};

#endif
