/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:39:45 by marvin            #+#    #+#             */
/*   Updated: 2024/03/07 17:39:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

std::string Contact::_getInput(std::string str) const {
    std::string input = "";
    bool        valid = false;
    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = true;
        else {
            std::cin.clear();
            std::cout << "Invalid input; please try again.\n";
        }
    } while (!valid);
    return (input);
}

void    Contact::init(void) {
    std::cin.ignore();
    this->_FirstName = this->_getInput("Please enter you first name: ");
    this->_LastName = this->_getInput("Please enter your last name: ");
    this->_NickName = this->_getInput("Please enter your nickname: ");
    this->_PhoneNumber = this->_getInput("Please enter your phone number: ");
    this->_DarkestSecret = this->_getInput("Please enter your darkest secret: ");
    std::cout << std::endl;
}


std::string Contact::_printLen(std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::setIndex(int i) {
    this->_index = i;
}

void    Contact::view(int index) const {
    if (this->_FirstName.empty() || this->_LastName.empty() || this->_NickName.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_FirstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_LastName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_NickName) << std::flush;
    std::cout << "|\n";
}

void    Contact::display(int index) const {
    if (this->_FirstName.empty() || this->_LastName.empty() || this->_NickName.empty() || this->_PhoneNumber.empty() || this->_DarkestSecret.empty())
        return ;
    std::cout << "\n------------| CONTACT #" << index << " |------------\n";
    std::cout << "First Name:\t\t" << this->_FirstName;
    std::cout << "\nLast Name:\t\t" << this->_LastName;
    std::cout << "\nNickname:\t\t" << this->_NickName;
	std::cout << "\nPhone number:\t\t" << this->_PhoneNumber;
	std::cout << "\nDarkest secrect:\t" << this->_DarkestSecret << std::endl;
	std::cout << "\n";
}