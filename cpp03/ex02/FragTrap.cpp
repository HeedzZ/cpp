/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:07:18 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/19 21:07:18 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    std::cout << "FragTrap " << this->_name << " has been constructed !" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " has been destructed !" << std::endl;
}

void    FragTrap::highFive( void ) {
    if ( this->_energyPoints <= 0 ) {
        std::cout << "FragTrap " << this->_name << " is out of energy !" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " high fives everybody." << std::endl;
    this->_energyPoints -= 1;
}

