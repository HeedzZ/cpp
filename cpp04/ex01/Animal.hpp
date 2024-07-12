/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:38:26 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/24 15:38:26 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
protected:
	std::string _type;
public:
	Animal(void);
	Animal(std::string type);
	virtual ~Animal(void);
	Animal(const Animal& src);
	Animal& operator=(const Animal& rhs);

	virtual void	makeSound(void) const;
	std::string		getType(void) const;
};

#endif