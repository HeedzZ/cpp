/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:52:54 by marvin            #+#    #+#             */
/*   Updated: 2024/03/11 15:52:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	std::string _name;
	Weapon* _weapon;

public:
	HumanB(std::string name);
	~HumanB();
	
	void	attack(void) const;
	void	setWeapon(Weapon& weapon);
};

#endif