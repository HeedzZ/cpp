/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:38:26 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/24 15:38:26 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal(void);
	AAnimal(std::string type);
	virtual ~AAnimal(void);
	AAnimal(const AAnimal& src);
	AAnimal& operator=(const AAnimal& rhs);

	virtual void	makeSound(void) const = 0;
	std::string		getType(void) const;
};

#endif