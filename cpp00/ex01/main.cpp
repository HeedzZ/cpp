/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:39:50 by marvin            #+#    #+#             */
/*   Updated: 2024/03/07 17:39:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include <iostream>

int main(void)
{
    PhoneBook book;

    std::string input = "";
	std::cout << "\n📞 Welcome to Your Awesome PhoneBook 📖\n";
    while (input.compare("EXIT")) {
        if (input.compare("ADD") == 0)
            book.addContact();
        if (input.compare("SEARCH") == 0) {
            book.printContacts();
            book.search();
        }
		else
			book.menu();
        std::cout << "> " << std::flush;
        std::cin >> input;
    }
    return 0;
}
