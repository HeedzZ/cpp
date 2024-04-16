/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:17:55 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/04 15:17:55 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been cronstructed !" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destructed !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &to_cpy)
{
	*this = to_cpy;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& original)
{
    this->_name = original._name;
    this->_hitPoints = original._hitPoints;
    this->_energyPoints = original._energyPoints;
    this->_attackDamage = original._attackDamage;
    return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		return ;
	}
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= amount)
    {
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
    _hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= amount)
    {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " repairs it self for " << amount << " hit points!" << std::endl;
    _energyPoints -= 1;
    _hitPoints += amount;
}