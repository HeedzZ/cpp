#include "MutantStack.hpp"
#include <iostream>
#include <stack>

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Elements in MutantStack:" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::list<int> stdList;

    stdList.push_back(5);
    stdList.push_back(17);
    stdList.push_back(3);
    stdList.push_back(5);
    stdList.push_back(737);
    stdList.push_back(0);

    std::cout << "\nElements in std::list:" << std::endl;
    for (std::list<int>::iterator it2 = stdList.begin(); it2 != stdList.end(); ++it2)
        std::cout << *it2 << std::endl;

    return 0;
}

