/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:15:58 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/26 14:15:58 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	~WrongAnimal(void);
	WrongAnimal(const WrongAnimal& src);
	WrongAnimal& operator=(const WrongAnimal& rhs);

	void	makeSound(void) const;
	std::string		getType(void) const;
};

#endif