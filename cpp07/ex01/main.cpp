#include <iostream>
#include "Iter.hpp"


template <typename T>
void print(const T& element) {
    std::cout << element << std::endl;
}

template <typename T>
void compare(const T& element) {
    static T max_value = element;
    if (element > max_value) {
        max_value = element;
    }
    std::cout << "Max jusqu'à présent: " << max_value << std::endl;
}

int main() {

    int arr_int[] = {1, 2, 3, 4, 5};
    std::cout << "Test avec des entiers (affichage) :" << std::endl;
    iter(arr_int, 5, print);

    std::string arr_str[] = {"chaine1", "chaine2", "chaine3"};
    std::cout << "\nTest avec des chaînes (affichage) :" << std::endl;
    iter(arr_str, 3, print);

    double arr_double[] = {1.5, 2.5, 3.5};
    std::cout << "\nTest avec des doubles (affichage) :" << std::endl;
    iter(arr_double, 3, print);

    std::cout << "\nTest avec une fonction de comparaison :" << std::endl;
    iter(arr_int, 5, compare);

    return 0;
}
