/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:52:27 by marvin            #+#    #+#             */
/*   Updated: 2024/01/26 13:52:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Zombie object " << this->_name << " created\n";
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie object " << this->_name << " destroyed\n";
}

void	Zombie::announce()
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ...\n";
}