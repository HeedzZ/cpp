/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:43:02 by marvin            #+#    #+#             */
/*   Updated: 2024/01/26 13:43:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	~Zombie(void);
	void	announce(void);
	void	setName(std::string name);
};

Zombie*    zombieHorde( int N, std::string name );

#endif