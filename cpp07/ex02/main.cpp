#include <iostream>
#include "Array.hpp"

int main()
{
    try {
        // Test with an array of 5 elements
        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); ++i)
            arr[i] = i * 10;

        std::cout << "Array of integers: " << std::endl;
        for (unsigned int i = 0; i < arr.size(); ++i)
            std::cout << arr[i] << std::endl;

        // Test copy constructor
        Array<int> arr_copy = arr;
        std::cout << "\nCopied array: " << std::endl;
        for (unsigned int i = 0; i < arr_copy.size(); ++i)
            std::cout << arr_copy[i] << std::endl;

        // Test assignment operator
        Array<int> arr_assign(3);
        arr_assign = arr;
        std::cout << "\nArray after assignment: " << std::endl;
        for (unsigned int i = 0; i < arr_assign.size(); ++i)
            std::cout << arr_assign[i] << std::endl;

        // Test exception handling (out-of-bounds index)
        std::cout << "\nAttempting to access out of bounds: " << std::endl;
        std::cout << arr[10] << std::endl;  // Should throw an exception

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

