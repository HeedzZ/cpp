/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:39:37 by marvin            #+#    #+#             */
/*   Updated: 2024/03/07 17:39:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::menu(void) {
    std::cout << "\n-------------| MENU |--------------\n";
    std::cout << "ADD\t: To add a contact.\n";
    std::cout << "SEARCH\t: To search for a contact.\n";
    std::cout << "EXIT\t: to quite the PhoneBook.\n";
    std::cout << "----------------------------------\n\n";
}

void    PhoneBook::addContact(void) {
    static int  i;
    this->_contacts[i % 8].init();
    this->_contacts[i % 8].setIndex(i % 8);
    i++;
}

void    PhoneBook::printContacts(void) const {
    std::cout << "------------| PHONBOOK CONTACTS |------------\n";
    for (size_t i = 0; i < 8; i++)
        this->_contacts[i].view(i);
    std::cout << "\n";
}

int     PhoneBook::_readInput() const {
    int     input = -1;
    bool    valid = false;
    do
    {
        std::cout << "Please enter the contact index: " << std::flush;
        std::cin >> input;
        if (std::cin.good() && (input >= 0 && input <= 8)) {
            valid = true;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid index; please re-enter.\n";
        }
    } while (!valid);
    return (input);
}

void    PhoneBook::search(void) const {
    int i = this->_readInput();
    this->_contacts[i].display(i);
}