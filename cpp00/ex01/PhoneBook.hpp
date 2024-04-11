/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:45:17 by marvin            #+#    #+#             */
/*   Updated: 2024/01/24 12:45:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact		_contacts[8];
	int         _readInput(void) const;

public:
	PhoneBook();
	~PhoneBook();
	void	addContact(void);
	void	printContacts(void) const;
	void	search(void) const;
	void	menu(void);
};

#endif