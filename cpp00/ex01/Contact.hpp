/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:45:03 by marvin            #+#    #+#             */
/*   Updated: 2024/01/24 12:45:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string.h>
#include <cctype>
#include <limits>

class Contact
{
private:
	std::string _FirstName;
	std::string _LastName;
	std::string _NickName;
	std::string _PhoneNumber;
	std::string _DarkestSecret;
	std::string _index;

	std::string _printLen(std::string str) const;
	std::string _getInput(std::string str) const;

public:
	Contact();
	~Contact();
	void	init(void);
	void	view(int index) const;
	void	display(int	index) const;
	void	setIndex(int i);
	int		check_contact(int index) const;
};

#endif