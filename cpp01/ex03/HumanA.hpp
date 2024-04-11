/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:46:06 by marvin            #+#    #+#             */
/*   Updated: 2024/03/11 15:46:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	std::string _name;
	Weapon& _weapon;
	HumanA();
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	
	void	attack(void) const;
};

#endif